#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&timer_ui,
            SIGNAL(timeout()),
            this,
            SLOT(atualiza_interface()));
    timer_ui.start(41);

    connect(&timer_processo_fisico,
            SIGNAL(timeout()),
            this,
            SLOT(processo_fisico()));
    timer_processo_fisico.start(10);
    tb.start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

extern double tanque1;
extern double tanque2;

extern uint8_t pin_s11;
extern uint8_t pin_s12;
extern uint8_t pin_v1;

extern uint8_t pin_s21;
extern uint8_t pin_s22;
extern uint8_t pin_pump;

void MainWindow::atualiza_interface(){
    ui->toolButton_s11->setPower(pin_s11);
    ui->toolButton_s12->setPower(pin_s12);
    ui->toolButton_v1->setPower(pin_v1);

    ui->toolButton_s21->setPower(pin_s21);
    ui->toolButton_s22->setPower(pin_s22);
    ui->toolButton_pump->setPower(pin_pump);

    ui->toolButton_tanque1->setValue((int) tanque1);
    ui->toolButton_tanque2->setValue((int) tanque2);
}

void MainWindow::processo_fisico(){
    if(pin_v1){
        tanque1 += .1;
        if(tanque1 > 100)
            tanque1 = 100;
    }

    if(pin_pump){
        tanque1 -= .5;
        tanque2 += .5;
        if(tanque2 > 100)
            tanque2 = 100;
    }

    if(tanque1 > 0) // Evaporação
        tanque1 -= .001;

    if(tanque2 > 0) // Evaporação
        tanque2 -= .01;

    pin_s11 = (tanque1>10);
    pin_s12 = (tanque1>90);

    pin_s21 = (tanque2>10);
    pin_s22 = (tanque2>90);
}
