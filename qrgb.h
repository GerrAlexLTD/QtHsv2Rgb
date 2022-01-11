#ifndef QRGB_H
#define QRGB_H

#include <QObject>

class QRgb : public QObject
{
    Q_OBJECT
public:
    explicit QRgb(QObject *parent = nullptr);

signals:

};

#endif // QRGB_H
