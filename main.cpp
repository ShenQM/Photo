#include <iostream>

#include <QApplication>
#include <QDebug>
#include <QtWidgets/QWidget>
#include <QString>

#include "UI/Forms/ui_mainwindow.h"
#include "UI/MainWindow.h"
#include "UI/ImageWidget.h"

void TestImageWidget()
{
    sqm::ImageWidget *imageWidget = new sqm::ImageWidget;
    QString fileName = "../../data/lena.jpg";
    imageWidget->Setpixmap(fileName);
    imageWidget->show();
}

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    //TestImageWidget();
    sqm::MainWindow mainwindow;
    mainwindow.showMaximized();
    std::cout << "Hello, World!" << std::endl;
    return a.exec();
}