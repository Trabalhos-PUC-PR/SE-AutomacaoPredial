#include "mainwindow.h"
#include "ui_mainwindow.h"

double tanque1 = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&timer_ui,
            SIGNAL(timeout()),
            this,
            SLOT(atualiza_interface()));
    timer_ui.start(33);

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

extern uint8_t pin_s11;
extern uint8_t pin_s12;
extern uint8_t pin_v1;

void MainWindow::atualiza_interface(){
    ui->toolButton_s11->setPower(pin_s11);
    ui->toolButton_s12->setPower(pin_s12);
    ui->toolButton_v1->setPower(pin_v1);
    ui->toolButton_tanque1->setValue(tanque1);
}

void MainWindow::processo_fisico(){
    if(pin_v1){
        tanque1 += .1;
        if(tanque1 > 100)
            tanque1 = 100;
    }

    if(tanque1 > 0) // Evaporação
        tanque1 -= .001;

    pin_s11 = (tanque1>10);
    pin_s12 = (tanque1>90);
}
