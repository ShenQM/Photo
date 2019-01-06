//
// Created by  Shen Quanmin on 2019-01-06.
//

#include "ImageWidget.h"

namespace sqm{
    ImageWidget::ImageWidget(QWidget *parent) :QWidget(parent), m_pixmap(nullptr), m_brush(nullptr),
    m_scrollArea(nullptr), m_scale(1.0)
    {
        setParent(parent);
    }

    ImageWidget::~ImageWidget()
    {
        if(nullptr != m_pixmap){
            delete m_pixmap;
            m_pixmap = nullptr;
        }

        if(nullptr != m_brush){
            delete m_brush;
            m_brush = nullptr;
        }

        if(nullptr != m_scrollArea){
            delete m_scrollArea;
            m_scrollArea = nullptr;
        }
    }

    void ImageWidget::Setpixmap(const QString &fileName)
    {
        if(nullptr == m_pixmap){
            m_pixmap = new QPixmap;
        }
        m_pixmap->load(fileName);

    }

    void ImageWidget::Setpixmap(const QPixmap &pixmap)
    {
        if(nullptr == m_pixmap){
            m_pixmap = new QPixmap;
        }
        *m_pixmap = pixmap;
    }

    void ImageWidget::paintEvent(QPaintEvent *event)
    {
        double sx = (double)width()/m_pixmap->width();
        double sy = (double)height() / m_pixmap->height();
        m_scale = sx < sy ? sx : sy;

        QPainter painter(this);
        painter.save();
        painter.scale(m_scale, m_scale);
        painter.drawPixmap(0, 0, *m_pixmap);
        painter.restore();
    }
}