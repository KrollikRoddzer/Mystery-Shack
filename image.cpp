#include "image.h"

Image::Image(QWidget* parent, QString path_) : QWidget(parent), path(path_)
{
    this->setFixedSize(300, 300);
}

void Image::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawPixmap(0, 0, 300, 300, QPixmap(path));
}
