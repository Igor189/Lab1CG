#pragma once
#include <QWidget>
#include <QSlider>
#include<QColorDialog>
#include<QPushButton>

class BrushSettings : public QWidget
{
	Q_OBJECT

public:
	BrushSettings(QWidget* parent = nullptr);

signals:
	void PenWidthChanged(int width);
	void ColorChanged(const QColor& color);

private slots:
	void OnColorButtonClicked();
	void OnPenWidthChanged(int width);
	void OnColorSelected(const QColor& color);

private:
	QSlider* m_pSlider;
	QColorDialog* m_pColorDialog;
	QPushButton* m_pColorButton;
};