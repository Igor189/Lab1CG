#include "PaintWidget.h"
#include <QPainter>

PaintWidget::PaintWidget()
{
    setAttribute(Qt::WA_StaticContents);
    m_bIsModified = false;
    m_nPenWidth = 1;
    m_PenColor = Qt::black;
    m_Image = QImage(800, 600, QImage::Format_RGB32);
    m_Image.fill(qRgb(255, 255, 255));
}

void PaintWidget::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) 
    {
        m_LastPoint = event->pos();
    }
}

void PaintWidget::mouseMoveEvent(QMouseEvent* event)
{
    if (event->buttons() & Qt::LeftButton)
        DrawLineTo(event->pos());
}

void PaintWidget::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) 
    {
        DrawLineTo(event->pos());
    }
}

void PaintWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    QRect dirtyRect = event->rect();
    painter.drawImage(dirtyRect, m_Image, dirtyRect);
}

void PaintWidget::DrawLineTo(const QPoint& endPoint)
{
    QPainter painter(&m_Image);
    painter.setPen(QPen(m_PenColor, m_nPenWidth, Qt::SolidLine, Qt::RoundCap,
        Qt::RoundJoin));
    painter.drawLine(m_LastPoint, endPoint);
    m_bIsModified = true;

    int rad = (m_nPenWidth / 2) + 2;
    update(QRect(m_LastPoint, endPoint).normalized()
        .adjusted(-rad, -rad, +rad, +rad));
    m_LastPoint = endPoint;
}