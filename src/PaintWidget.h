#pragma once
#include <QWidget>
#include <QMouseEvent>


class PaintWidget : public QWidget {
public:
    PaintWidget();

public slots:
    void SetPenWidth(int width);
    void SetPenColor(const QColor& color);

protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void paintEvent(QPaintEvent* event) override;
private:
    void DrawLineTo(const QPoint& endPoint);

    int m_nPenWidth;
    QColor m_PenColor;
    QPixmap m_Pixmap;
    QPoint m_LastPoint;
};