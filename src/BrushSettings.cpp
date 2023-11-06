#include "BrushSettings.h"
#include<QPushButton>
#include<QHBoxLayout>

BrushSettings::BrushSettings(QWidget* parent) :QWidget(parent)
{
    m_pSlider = new QSlider(Qt::Horizontal, this);
    m_pSlider->setRange(1, 50);
    connect(m_pSlider, &QSlider::valueChanged, this, &BrushSettings::OnPenWidthChanged);

    m_pColorDialog = new QColorDialog(this);
    connect(m_pColorDialog, &QColorDialog::colorSelected, this, &BrushSettings::OnColorSelected);

    m_pColorButton = new QPushButton("Choose Color", this);
    connect(m_pColorButton, &QPushButton::clicked, this, &BrushSettings::OnColorButtonClicked);

    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(m_pSlider);
    layout->addWidget(m_pColorButton);

    this->setLayout(layout);
}

void BrushSettings::OnColorButtonClicked()
{
    m_pColorDialog->open();
}

void BrushSettings::OnColorSelected(const QColor& color)
{
    emit ColorChanged(color);
}

void BrushSettings::OnPenWidthChanged(int width)
{
    emit PenWidthChanged(width);
}
