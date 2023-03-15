#include "qt-vtk-gui-demo.h"
#include "stdafx.h"
#include "vtkLine.h"

VTK_MODULE_INIT(vtkRenderingOpenGL2);
VTK_MODULE_INIT(vtkInteractionStyle);
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
using namespace std;


ShellDIS::ShellDIS(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	//显示DICOM文件
	m_renderer = vtkSmartPointer<vtkRenderer>::New();
	m_actor = vtkSmartPointer<vtkActor>::New();
	m_renderWindow = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
	m_interactorStyle = vtkSmartPointer<vtkInteractorStyleImage>::New();
}

void ShellDIS::ReadDataFile(const std::string& file)
{
	vtkIndent indent;

	std::ifstream fin(file);
	if (!fin)
	{
		std::string msg("can not open file ");
		msg += file;
		throw std::runtime_error(msg.c_str());
	}
	std::string line;


	while (std::getline(fin, line))
	{
		cout << line << std::endl;
		istringstream iss(line);
		double x1, y1, z1;
		double x2, y2, z2;
		iss >> x1 >> y1 >> z1;
		iss >> x2 >> y2 >> z2;
		addPoint(x1, y1);
		addPoint(x2, y2);
	}

	auto vtkPoints = pointListToVTKPoints();
	auto vtkLines = addLine();

	vtkSmartPointer<vtkPolyData> polydata = vtkSmartPointer<vtkPolyData>::New();
	polydata->SetPoints(vtkPoints);// 几何数据
	polydata->SetLines(vtkLines);// 拓扑数据

	vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	mapper->SetInputData(polydata);
	m_actor->SetMapper(mapper);

	m_renderer->AddActor(m_actor);
	m_renderWindow->AddRenderer(m_renderer);

	ui.openGLWidget->SetRenderWindow(m_renderWindow);

	QVTKInteractor* interactor = ui.openGLWidget->GetInteractor();
	interactor->SetInteractorStyle(m_interactorStyle);
	interactor->SetRenderWindow(m_renderWindow);
}

void ShellDIS::addPoint(double x1, double y1)
{
	m_point_list.push_back(c_point(x1, y1));
}

vtkSmartPointer<vtkPoints> ShellDIS::pointListToVTKPoints(void)
{
	vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
	for (auto& item : m_point_list)
	{
		points->InsertNextPoint(item.x, item.y, 0);
	}
	//points->InsertNextPoint(0, 0, 0);//0
	//points->InsertNextPoint(2, 0, 0);//1
	//points->InsertNextPoint(3, 1, 0);//2
	//points->InsertNextPoint(2, 2, 0);//3
	//points->InsertNextPoint(0, 2, 0);//4

	return points;
}

vtkSmartPointer<vtkCellArray> ShellDIS::addLine()
{
	vtkSmartPointer<vtkCellArray> lines = vtkSmartPointer<vtkCellArray>::New();
	for (int i = 0; i < m_point_list.size(); i+=2)
	{
		vtkSmartPointer<vtkLine> line = vtkSmartPointer<vtkLine>::New();
		//第一个参数是线的端点号，第二个参数是线端点对应点的ID
		line->GetPointIds()->SetId(0, i);// line 由两个点组成，方向是第一个点指向第二个点
		line->GetPointIds()->SetId(1, i+1);// 增加再多的点也没用，它什么也不会发生
		lines->InsertNextCell(line);
	}
	return lines;
}
