#include "qt-vtk-gui-demo.h"
#include "stdafx.h"
#include <QtWidgets/QApplication>

#include <iostream>
using namespace std;
#include <vtkCellArray.h>
#include <vtkIdList.h>
#include <vtkNew.h>
#include <vtkPolyData.h>
#include <vtkTriangle.h>

#include <vtkAppendFilter.h>
#include <vtkSphereSource.h>
#include <vtkUnstructuredGrid.h>
#include <vtkUnstructuredGridReader.h>
//#include <vtkXMLUnstructuredGridReader.h>

#include <vtkActor.h>
#include <vtkCamera.h>
#include <vtkDataSetMapper.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkSmartPointer.h>

#include <algorithm>
#include <array>
#include <string>

namespace {
    vtkSmartPointer<vtkUnstructuredGrid>
        ReadUnstructuredGrid(std::string const& fileName);
}

int main(int argc, char* argv[])
{
    // Vis Pipeline
    vtkNew<vtkNamedColors> colors;

    vtkNew<vtkRenderer> renderer;

    vtkNew<vtkRenderWindow> renderWindow;
    renderWindow->SetSize(640, 480);
    renderWindow->AddRenderer(renderer);

    vtkNew<vtkRenderWindowInteractor> interactor;
    interactor->SetRenderWindow(renderWindow);

    renderer->SetBackground(colors->GetColor3d("Wheat").GetData());
    renderer->UseHiddenLineRemovalOn();
    std::string file_vtk("./data-file/biaxial_101.vtk");
    std::cout << "Loading: " << file_vtk << std::endl;
    auto unstructuredGrid = ReadUnstructuredGrid(std::string(file_vtk));

    // Visualize
    vtkNew<vtkDataSetMapper> mapper;
    mapper->SetInputData(unstructuredGrid);
    mapper->ScalarVisibilityOff();

    vtkNew<vtkProperty> backProp;
    backProp->SetDiffuseColor(colors->GetColor3d("Banana").GetData());
    backProp->SetSpecular(.6);
    backProp->SetSpecularPower(30);

    vtkNew<vtkActor> actor;
    actor->SetMapper(mapper);
    actor->SetBackfaceProperty(backProp);
    actor->GetProperty()->SetDiffuseColor(colors->GetColor3d("Tomato").GetData());
    actor->GetProperty()->SetSpecular(.3);
    actor->GetProperty()->SetSpecularPower(30);
    actor->GetProperty()->EdgeVisibilityOn();
    renderer->AddActor(actor);
    renderer->GetActiveCamera()->Azimuth(45);
    renderer->GetActiveCamera()->Elevation(45);
    renderer->ResetCamera();
    renderWindow->SetWindowName("ReadAllUnstructuredGridTypes");
    renderWindow->Render();
    interactor->Start();

    return EXIT_SUCCESS;
}

namespace {
    vtkSmartPointer<vtkUnstructuredGrid>
        ReadUnstructuredGrid(std::string const& fileName)
    {
        vtkSmartPointer<vtkUnstructuredGrid> unstructuredGrid;
        std::string extension = "";
        if (fileName.find_last_of(".") != std::string::npos)
        {
            extension = fileName.substr(fileName.find_last_of("."));
        }

        // Drop the case of the extension
        std::transform(extension.begin(), extension.end(), extension.begin(),
            ::tolower);

        if (extension == ".vtk")
        {
            vtkNew<vtkUnstructuredGridReader> reader;
            reader->SetFileName(fileName.c_str());
            reader->Update();
            unstructuredGrid = reader->GetOutput();
        }
        else
        {
            vtkNew<vtkSphereSource> source;
            source->Update();
            vtkNew<vtkAppendFilter> appendFilter;
            appendFilter->AddInputData(source->GetOutput());
            appendFilter->Update();
            unstructuredGrid = appendFilter->GetOutput();
        }

        return unstructuredGrid;
    }

} // namespace


//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    //ShellDIS w;
//    //w.ReadDataFile("line_information.txt");
//    //w.show();
//
//    std::cout<<"Hello World!"<<std::endl;
//
//
//
//    return a.exec();
//}
