//
// Created by  Shen Quanmin on 2019-01-06.
//

#ifndef PHOTO_MAINWINDOW_H
#define PHOTO_MAINWINDOW_H
#include <iostream>
#include <QObject>
#include <QMainWindow>
#include <QWidget>
#include <QMenu>
#include <QAction>

#include "Forms/ui_mainwindow.h"
#include "ImageWidget.h"

namespace  sqm {
class MainWindow:public QMainWindow, public Ui::MainWindow
    {
    Q_OBJECT
    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    protected:
        void resizeEvent(QResizeEvent *event);
    private:
        void CreateActions();
        void CreateMenus();
    private:
        //Menus
        QMenu *m_fileMenu;
        QMenu *m_cpMenu;

        //Actions
        QAction *m_openAction;
        QAction *m_hdrAction;

        ImageWidget *m_imageWidget;
    };
}

#endif //PHOTO_MAINWINDOW_H
