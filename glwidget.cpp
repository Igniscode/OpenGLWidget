#include "glwidget.h"

#include <QTimer>

Helper::Helper() {
	QLinearGradient gradient(QPointF(50, -20), QPointF(80, 20));
	gradient.setColorAt(0.0, Qt::white);
	gradient.setColorAt(1.0, QColor(162, 100, 149));

	background = QBrush(QColor(4, 92, 64));
	circleBrush = QBrush(gradient);
	circlePen = QPen(Qt::black);
	circlePen.setWidth(1);
	textPen = QPen(Qt::white);
	textFont.setPixelSize(50);
}

void Helper::paint(QPainter *painter,
	QPaintEvent *e, int elapsed) {
//	painter->fillRect(e->rect(), background);
//	painter->fillRect(e->rect(), background);
//	painter->translate(_hheight,_hwidth);
	painter->translate(250, 150);
	painter->save();
	painter->setBrush(circleBrush);
	painter->setPen(circlePen);
	painter->rotate(elapsed * 0.030);

	qreal r = elapsed / 1000.0;
	int n = 30;
	for (int i = 0; i < n; ++i) {
		painter->rotate(30);
		qreal factor = (i + r) / n;
		qreal radius = 0 + 120.0 * factor;
		qreal circleRadius = 1 + factor * 20;
		painter->drawEllipse(QRectF(radius, -circleRadius,
			circleRadius * 2, circleRadius * 2));
	}
	painter->restore();

	painter->setPen(textPen);
	painter->setFont(textFont);
	painter->drawText(QRect(-100, -50, 250, 100), Qt::AlignCenter, QStringLiteral("prototype"));
}

GLWidget::GLWidget(Helper *helper, QWidget *parent)
	: QOpenGLWidget(parent), helper(helper)
{
	elapsed = 0;
//	resize(200, 200);
	setAutoFillBackground(false);
}

void GLWidget::animate()
{
	elapsed = (elapsed + qobject_cast<QTimer*>(sender())->interval()) % 1000;
	update();
}

void GLWidget::paintEvent(QPaintEvent *e)
{
	QPainter painter;
	painter.begin(this);
	painter.setRenderHint(QPainter::Antialiasing);
	helper->paint(&painter, e, elapsed);
	painter.end();
}