#ifndef QHSV_H
#define QHSV_H
#include <QObject>
#include <QRgb>

class QHsv : public QObject
{
    Q_OBJECT
    uint16_t h;
    uint8_t s, v;
public:
    QHsv();
    QHsv(uint16_t, uint8_t, uint8_t);
    QRgb toRgb();
    void setHue(uint16_t);
    void setSaturation(uint8_t);
    void setValue(uint8_t);
    void incHue();
    void incSaturation();
    void incValue();
};

#endif // QHSV_H
