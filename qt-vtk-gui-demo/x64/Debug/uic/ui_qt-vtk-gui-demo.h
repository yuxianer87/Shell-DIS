/********************************************************************************
** Form generated from reading UI file 'qt-vtk-gui-demo.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_2D_VTK_2D_GUI_2D_DEMO_H
#define UI_QT_2D_VTK_2D_GUI_2D_DEMO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "QVTKOpenGLWidget.h"

QT_BEGIN_NAMESPACE

class Ui_hydraulicslopedigitaltwinClass
{
public:
    QAction *actionopen;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QVTKOpenGLWidget *openGLWidget;
    QMenuBar *menuBar;
    QMenu *menufile;
    QMenu *menugeometry;
    QMenu *menuMaterial;
    QMenu *menuAnchorage;
    QMenu *menuMonitor;
    QMenu *menuCalculation;
    QMenu *menuShow;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *hydraulicslopedigitaltwinClass)
    {
        if (hydraulicslopedigitaltwinClass->objectName().isEmpty())
            hydraulicslopedigitaltwinClass->setObjectName(QString::fromUtf8("hydraulicslopedigitaltwinClass"));
        hydraulicslopedigitaltwinClass->resize(929, 613);
        actionopen = new QAction(hydraulicslopedigitaltwinClass);
        actionopen->setObjectName(QString::fromUtf8("actionopen"));
        centralWidget = new QWidget(hydraulicslopedigitaltwinClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        openGLWidget = new QVTKOpenGLWidget(centralWidget);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));

        horizontalLayout->addWidget(openGLWidget);

        hydraulicslopedigitaltwinClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(hydraulicslopedigitaltwinClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 929, 23));
        menufile = new QMenu(menuBar);
        menufile->setObjectName(QString::fromUtf8("menufile"));
        menugeometry = new QMenu(menuBar);
        menugeometry->setObjectName(QString::fromUtf8("menugeometry"));
        menuMaterial = new QMenu(menuBar);
        menuMaterial->setObjectName(QString::fromUtf8("menuMaterial"));
        menuAnchorage = new QMenu(menuBar);
        menuAnchorage->setObjectName(QString::fromUtf8("menuAnchorage"));
        menuMonitor = new QMenu(menuBar);
        menuMonitor->setObjectName(QString::fromUtf8("menuMonitor"));
        menuCalculation = new QMenu(menuBar);
        menuCalculation->setObjectName(QString::fromUtf8("menuCalculation"));
        menuShow = new QMenu(menuBar);
        menuShow->setObjectName(QString::fromUtf8("menuShow"));
        hydraulicslopedigitaltwinClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(hydraulicslopedigitaltwinClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        hydraulicslopedigitaltwinClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(hydraulicslopedigitaltwinClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        hydraulicslopedigitaltwinClass->setStatusBar(statusBar);

        menuBar->addAction(menufile->menuAction());
        menuBar->addAction(menugeometry->menuAction());
        menuBar->addAction(menuMaterial->menuAction());
        menuBar->addAction(menuAnchorage->menuAction());
        menuBar->addAction(menuMonitor->menuAction());
        menuBar->addAction(menuCalculation->menuAction());
        menuBar->addAction(menuShow->menuAction());
        menufile->addAction(actionopen);

        retranslateUi(hydraulicslopedigitaltwinClass);

        QMetaObject::connectSlotsByName(hydraulicslopedigitaltwinClass);
    } // setupUi

    void retranslateUi(QMainWindow *hydraulicslopedigitaltwinClass)
    {
        hydraulicslopedigitaltwinClass->setWindowTitle(QApplication::translate("hydraulicslopedigitaltwinClass", "hydraulicslopedigitaltwin", nullptr));
        actionopen->setText(QApplication::translate("hydraulicslopedigitaltwinClass", "open", nullptr));
        pushButton->setText(QApplication::translate("hydraulicslopedigitaltwinClass", "PushButton", nullptr));
        menufile->setTitle(QApplication::translate("hydraulicslopedigitaltwinClass", "Project", nullptr));
        menugeometry->setTitle(QApplication::translate("hydraulicslopedigitaltwinClass", "Geometry", nullptr));
        menuMaterial->setTitle(QApplication::translate("hydraulicslopedigitaltwinClass", "Material", nullptr));
        menuAnchorage->setTitle(QApplication::translate("hydraulicslopedigitaltwinClass", "Anchorage", nullptr));
        menuMonitor->setTitle(QApplication::translate("hydraulicslopedigitaltwinClass", "Monitor", nullptr));
        menuCalculation->setTitle(QApplication::translate("hydraulicslopedigitaltwinClass", "Calculation", nullptr));
        menuShow->setTitle(QApplication::translate("hydraulicslopedigitaltwinClass", "Display", nullptr));
    } // retranslateUi

};

namespace Ui {
    class hydraulicslopedigitaltwinClass: public Ui_hydraulicslopedigitaltwinClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_2D_VTK_2D_GUI_2D_DEMO_H
