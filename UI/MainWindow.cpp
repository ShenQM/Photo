//
// Created by  Shen Quanmin on 2019-01-06.
//

#include "MainWindow.h"

namespace sqm{
    MainWindow::MainWindow(QWidget *parent):QMainWindow(parent), m_imageWidget(nullptr), m_fileMenu(nullptr),
    m_openAction(nullptr), m_cpMenu(nullptr), m_hdrAction(nullptr)
    {
        setupUi(this);
        m_imageWidget = new ImageWidget(this);
//        imageScrollArea->addWidget(m_imageWidget);
        imageScrollArea->setWidget(m_imageWidget);
        m_imageWidget->setBaseSize(imageScrollArea->size());
        QString fileName = "../../data/aloeL.jpg";
        m_imageWidget->Setpixmap(fileName);
        imageScrollArea->horizontalScrollBarPolicy();

        CreateActions();
        CreateMenus();
    }

    MainWindow::~MainWindow()
    {
         if(nullptr != m_imageWidget){
             delete m_imageWidget;
             m_imageWidget = nullptr;
         }

         if(nullptr != m_openAction){
             delete m_openAction;
             m_openAction = nullptr;
         }

         if(nullptr != m_fileMenu)
         {
             delete m_fileMenu;
             m_fileMenu = nullptr;
         }

         if(nullptr != m_cpMenu){
             delete m_cpMenu;
             m_cpMenu = nullptr;
         }

         if(nullptr != m_hdrAction){
             delete m_hdrAction;
             m_hdrAction = nullptr;
         }
    }

    void MainWindow::resizeEvent(QResizeEvent *event)
    {
        QMainWindow::resizeEvent(event);
        std::cout << "width: " << width() <<std::endl;
        std::cout << "height: " << height() << std::endl;
    }

    void MainWindow::CreateActions()
    {
        m_openAction = new QAction(tr("&Open..."), this);
        m_openAction->setShortcuts(QKeySequence::Open);
        m_openAction->setStatusTip(tr("Open an existing file"));

        m_hdrAction = new QAction(tr("&Hdr..."), this);
    }

    void MainWindow::CreateMenus()
    {
        m_fileMenu = menuBar()->addMenu(tr("&File"));
        m_fileMenu->addAction(m_openAction);

        m_cpMenu = menuBar()->addMenu(tr("&Computational Photography"));
        m_cpMenu->addAction(m_hdrAction);
    }
}