#include "CustomProgressBar.h"
#include <QPainter>

CustomProgressBar::CustomProgressBar(QWidget* parent)
    : QProgressBar(parent) {
    m_color = Qt::blue; // 设置默认颜色为蓝色
}

void CustomProgressBar::paintEvent(QPaintEvent* event) {
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QRectF rect = QRectF(0, 0, width(), height());
    QRectF barRect = QRectF(0, 0, width() * (double)value() / maximum(), height());

    // 绘制进度条
    painter.fillRect(barRect, m_color);

    // 绘制边框
    painter.setPen(QPen(Qt::black, 1));
    painter.drawRect(rect);
}