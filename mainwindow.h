#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "qhsv.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QTimer *t;
    QHsv *source;
    QRgb *result;
    QString rgbParser(QRgb);
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void timerScreamReaction();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
