//
// Created by  Shen Quanmin on 2019-01-06.
//

#ifndef PHOTO_IMAGEWIDGET_H
#define PHOTO_IMAGEWIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QBrush>
#include <QPen>
#include <QPainter>
#include <QScrollArea>
#include <QString>

namespace sqm{
    class ImageWidget:public QWidget
    {
        Q_OBJECT
    public:
        ImageWidget(QWidget *parent = nullptr);
        ~ImageWidget();

        void Setpixmap(const QString &fileName);
        void Setpixmap(const QPixmap& pixmap);

    protected:
        void paintEvent(QPaintEvent *event);
    private:
        QPixmap *m_pixmap;
        QBrush *m_brush;
        QScrollArea *m_scrollArea;
        double m_scale;
    };
}

#endif //PHOTO_IMAGEWIDGET_H
