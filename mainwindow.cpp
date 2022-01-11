#include "mainwindow.h"
#include "ui_mainwindow.h"

#define INTERVAL 36

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->t = new QTimer();
    this->source = new QHsv(0, 100, 50);
    this->result = new QRgb();
    QObject::connect(t, &QTimer::timeout,
                     this, &MainWindow::timerScreamReaction);
    t->setInterval(INTERVAL);
    t->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerScreamReaction(){
    *result = source->toRgb();
    QString tmp = rgbParser(*result);
    ui->centralwidget->setStyleSheet(tmp);
    source->incHue();
}

QString MainWindow::rgbParser(QRgb source){
    return QString("QWidget{ background-color: "
                   "rgb("+QString::number((source&(255<<16))>>16)+","+
                   QString::number((source&(255<<8))>>8)+","+
                   QString::number(source&(255))+")}");
}
