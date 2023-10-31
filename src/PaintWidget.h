#pragma once
#include <QWidget>
#include <QMouseEvent>


class PaintWidget : public QWidget {
public:
    PaintWidget();

protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void paintEvent(QPaintEvent* event) override;

private:
    void DrawLineTo(const QPoint& endPoint);

    bool m_bIsModified;
    int m_nPenWidth;
    QColor m_PenColor;
    QImage m_Image;
    QPoint m_LastPoint;
};