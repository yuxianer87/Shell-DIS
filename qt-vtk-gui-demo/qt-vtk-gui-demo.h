#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_qt-vtk-gui-demo.h"

#include <vtkInteractorStyleImage.h>
#include <vtkSmartPointer.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkImageActor.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkCellArray.h>
#include <vtkLine.h>
#include <vtkPDataSetWriter.h>
#include "vtkPolyDataMapper.h"
#include <vtkPolyData.h>
#include <vtkSmartPointer.h>
#include "vtkAutoInit.h"
#include <string>
#include <list>

struct c_point
{
	c_point(double a, double b):x(a),y(b){}
	double x;
	double y;
};

class ShellDIS : public QMainWindow
{
    Q_OBJECT

public:
    ShellDIS(QWidget *parent = Q_NULLPTR);
	void ReadDataFile(const std::string& file);
private:
	void addPoint(double x1, double y1);
	vtkSmartPointer<vtkPoints> pointListToVTKPoints(void);
	vtkSmartPointer<vtkCellArray> addLine(void);
private:
    Ui::hydraulicslopedigitaltwinClass ui;
	QVTKInteractor* m_interactor;
	vtkSmartPointer<vtkGenericOpenGLRenderWindow> m_renderWindow;
	vtkSmartPointer<vtkInteractorStyleImage> m_interactorStyle;
	vtkSmartPointer<vtkRenderer> m_renderer;
	vtkSmartPointer<vtkActor> m_actor;
	std::list<c_point> m_point_list;
};
