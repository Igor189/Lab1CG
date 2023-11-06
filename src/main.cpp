#include <QApplication>
#include "PaintWidget.h"
#include "BrushSettings.h"
#include <QVBoxLayout>
#include <QObject>


int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    BrushSettings toolbar;
    PaintWidget paintWidget;

    QObject::connect(&toolbar, &BrushSettings::PenWidthChanged, &paintWidget, &PaintWidget::SetPenWidth);
    QObject::connect(&toolbar, &BrushSettings::ColorChanged, &paintWidget, &PaintWidget::SetPenColor);

    QVBoxLayout* layout = new QVBoxLayout;
    toolbar.setMaximumHeight(40);
    layout->addWidget(&toolbar);
    layout->addWidget(&paintWidget);

    QWidget* window = new QWidget;
    window->setLayout(layout);

    window->show();

    return app.exec();
}
