#ifndef IMAGE_H
#define IMAGE_H

#include <QWidget>
#include <QPainter>

class Image : public QWidget
{
    Q_OBJECT
public:
    Image(QWidget* parent = nullptr, QString path_ = "");
private:
    QString path;

    void paintEvent(QPaintEvent*) override;
};

#endif // IMAGE_H
