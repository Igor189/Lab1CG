#include "PaintWidget.h"
#include <QPainter>
#include <QDesktopWidget>

PaintWidget::PaintWidget()
{
    QDesktopWidget desktop;
    QSize screenSize = desktop.screenGeometry().size();
    setAttribute(Qt::WA_StaticContents);
    m_nPenWidth = 1;
    m_PenColor = Qt::black;
    m_Pixmap = QPixmap(screenSize);
    m_Pixmap.fill(Qt::white);
    setMinimumSize(640, 480);
}

void PaintWidget::SetPenWidth(int width)
{
    m_nPenWidth = width;
}

void PaintWidget::SetPenColor(const QColor& color)
{
    m_PenColor = color;
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
    painter.drawPixmap(dirtyRect, m_Pixmap, dirtyRect);
}

void PaintWidget::DrawLineTo(const QPoint& endPoint)
{
    QPainter painter(&m_Pixmap);
    painter.setPen(QPen(m_PenColor, m_nPenWidth, Qt::SolidLine, Qt::RoundCap,
        Qt::RoundJoin));
    painter.drawLine(m_LastPoint, endPoint);

    int rad = (m_nPenWidth / 2) + 2;
    update(QRect(m_LastPoint, endPoint).normalized()
        .adjusted(-rad, -rad, +rad, +rad));
    m_LastPoint = endPoint;
}
