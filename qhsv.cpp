#include "qhsv.h"
#define SCALER 2.55
#define RED 16
#define GREEN 8
#define BLUE 0
QHsv::QHsv(){
    this->h = 0;
    this->s = 0;
    this->v = 0;
}
QHsv::QHsv(uint16_t h, uint8_t s, uint8_t v){
    this->h = h;
    this->s = s;
    this->v = v;
}
QRgb QHsv::toRgb(){
    uint8_t Hi = (this->h/60)%6;
    double Vmin = ((100-this->s)*this->v)/100.0;
    double a = (this->v-Vmin)*((this->h%60)/60.0);
    double Vinc = Vmin+a;
    double Vdec = this->v-a;
    QRgb tmp = QRgb();
    switch(Hi){
    case(0):{
        tmp |= static_cast<int>(round(this->v*SCALER)) << RED;
        tmp |= static_cast<int>(round(Vinc*SCALER)) << GREEN;
        tmp |= static_cast<int>(round(Vmin*SCALER)) << BLUE;
        break;
    }
    case(1):{
        tmp |= static_cast<int>(round(Vdec*SCALER)) << RED;
        tmp |= static_cast<int>(round(this->v*SCALER)) << GREEN;
        tmp |= static_cast<int>(round(Vmin*SCALER)) << BLUE;
        break;
    }
    case(2):{
        tmp |= static_cast<int>(round(Vmin*SCALER)) << RED;
        tmp |= static_cast<int>(round(this->v*SCALER)) << GREEN;
        tmp |= static_cast<int>(round(Vinc*SCALER)) << BLUE;
        break;
    }
    case(3):{
        tmp |= static_cast<int>(round(Vmin*SCALER)) << RED;
        tmp |= static_cast<int>(round(Vdec*SCALER)) << GREEN;
        tmp |= static_cast<int>(round(this->v*SCALER)) << BLUE;
        break;
    }
    case(4):{
        tmp |= static_cast<int>(round(Vinc*SCALER)) << RED;
        tmp |= static_cast<int>(round(Vmin*SCALER)) << GREEN;
        tmp |= static_cast<int>(round(this->v*SCALER)) << BLUE;
        break;
    }
    case(5):{
        tmp |= static_cast<int>(round(this->v*SCALER)) << RED;
        tmp |= static_cast<int>(round(Vmin*SCALER)) << GREEN;
        tmp |= static_cast<int>(round(Vdec*SCALER)) << BLUE;
        break;
    }
    }
    return tmp;
}

void QHsv::setHue(uint16_t value){
    if (value > 360)
        this->h = 360;
    else this->h = value;
}
void QHsv::setSaturation(uint8_t value){
    if (value > 100)
        this->s = 100;
    else this->s = value;
}
void QHsv::setValue(uint8_t value){
    if (value > 100)
        this->v = 100;
    else this->v = value;
}

void QHsv::incHue(){
    if (this->h == 360)
        this->h = 0;
    else this->h++;
}
void QHsv::incSaturation(){
    if (this->s == 100)
        this->s = 0;
    else this->s++;
}
void QHsv::incValue(){
    if (this->v == 100)
        this->v = 0;
    else this->v++;
}
