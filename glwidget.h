#pragma once
#ifndef  GLWIDGET_H
#define GLWIDGET_H

#include <Qbrush>
#include <QFont>
#include <QPen>
#include <QPainter>
#include <QPaintevent>
#include <QTimer>
#include <QOpenglwidget>
#include <windows.h>
class Helper {
public:
	Helper();
	void paint(QPainter *painter,
		QPaintEvent *event, int elapsed);
private:
	QBrush background;
	QBrush circleBrush;
	QFont textFont;
	QPen circlePen;
	QPen textPen;
	int _hwidth = GetSystemMetrics(SM_CXSCREEN) / 2;
	int _hheight = GetSystemMetrics(SM_CYSCREEN) / 2;\

};
class GLWidget : public QOpenGLWidget {
	Q_OBJECT
public:
	GLWidget(Helper *helper, QWidget *parent);
	public slots :
	void animate();

protected:
	void paintEvent(QPaintEvent *e) override;

private:
	Helper * helper;
	int elapsed;


};

#endif // ! GLWIDGET_H
