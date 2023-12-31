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
    timer_ui.start(1);

    connect(ui->pushButton_drain_t2,
            SIGNAL(released()),
            this,
            SLOT(drainT2()));

    connect(ui->pushButton_drain_t3,
             SIGNAL(released()),
             this,
             SLOT(drainT3()));

    connect(ui->pushButton_pause,
            SIGNAL(released()),
            this,
            SLOT(congela()));

    connect(ui->pushButton_plus_t1,
            SIGNAL(released()),
            this,
            SLOT(add5_to_T1()));
    connect(ui->pushButton_plus_t2,
            SIGNAL(released()),
            this,
            SLOT(add5_to_T2()));
    connect(ui->pushButton_plus_t3,
            SIGNAL(released()),
            this,
            SLOT(add5_to_T3()));
    connect(ui->pushButton_minus_t1,
            SIGNAL(released()),
            this,
            SLOT(remove5_from_T1()));
    connect(ui->pushButton_minus_t2,
            SIGNAL(released()),
            this,
            SLOT(remove5_from_T2()));
    connect(ui->pushButton_minus_t3,
            SIGNAL(released()),
            this,
            SLOT(remove5_from_T3()));

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

#define t2_to_t3_transfer 0.2
#define t2_to_t3_proportion 4
#define Sx1Threshold 10
#define Sx2Threshold 99
#define pumpFlowRate 5
#define vaporizationRate 0//.04
#define valve1FlowRate .3
#define forceWaterLimit(tank)  tank = (tank > 100) ? 100 : tank
#define forceWaterMin(tank)  tank = (tank < 0) ? 0 : tank
#define SBx1Threshold 49
#define SBx2Threshold 51
#define boilerTempDecay .05
#define boilerTempIncrease .009

extern double tanque1;
extern double tanque2;
extern double tanque3;
extern double temp;

extern uint8_t pin_s11;
extern uint8_t pin_s12;
extern uint8_t pin_v1;

extern uint8_t pin_s21;
extern uint8_t pin_s22;
extern uint8_t pin_pump;

extern uint8_t pin_s31;
extern uint8_t pin_s32;
extern uint8_t pin_v2;

extern uint8_t pin_sb11;
extern uint8_t pin_sb12;
extern uint8_t pin_b1;

uint8_t freeze = 0;

void MainWindow::congela(){
    freeze = !freeze;
    freeze ?
        ui->pushButton_pause->setText("Resume") :
        ui->pushButton_pause->setText("Pause");
}

void MainWindow::drainT2(){
    tanque2 = 0;
};

void MainWindow::drainT3(){
    tanque3 = 0;
};

void MainWindow::add5_to_T1(){
    tanque1 += 5;
    forceWaterLimit(tanque1);
}
void MainWindow::add5_to_T2(){
    tanque2 += 5;
    forceWaterLimit(tanque2);
}
void MainWindow::add5_to_T3(){
    tanque3 += 5;
    forceWaterLimit(tanque3);
}
void MainWindow::remove5_from_T1(){
    tanque1 -= 5;
    forceWaterMin(tanque1);
}
void MainWindow::remove5_from_T2(){
    tanque2 -= 5;
    forceWaterMin(tanque2);
}
void MainWindow::remove5_from_T3(){
    tanque3 -= 5;
    forceWaterMin(tanque3);
}

void MainWindow::atualiza_interface(){
    ui->toolButton_s11->setPower(pin_s11);
    ui->toolButton_s12->setPower(pin_s12);
    ui->toolButton_v1->setPower(pin_v1);

    ui->toolButton_s21->setPower(pin_s21);
    ui->toolButton_s22->setPower(pin_s22);
    ui->toolButton_pump->setPower(pin_pump);

    ui->toolButton_s31->setPower(pin_s31);
    ui->toolButton_s32->setPower(pin_s32);
    ui->toolButton_v2->setPower(pin_v2);

    ui->toolButton_tanque1->setValue((int) tanque1);
    ui->toolButton_tanque2->setValue((int) tanque2);
    ui->toolButton_tanque3->setValue((int) tanque3);

    ui->label_p1_state->setText(QString::number(pin_pump));
    ui->label_v1_state->setText(QString::number(pin_v1));
    ui->label_v2_state->setText(QString::number(pin_v2));
    ui->label_t1_state->setText(QString::number(tanque1));
    ui->label_t2_state->setText(QString::number(tanque2));
    ui->label_t3_state->setText(QString::number(tanque3));
    ui->label_s11_state->setText(QString::number(pin_s11));
    ui->label_s12_state->setText(QString::number(pin_s12));
    ui->label_s21_state->setText(QString::number(pin_s21));
    ui->label_s22_state->setText(QString::number(pin_s22));
    ui->label_s31_state->setText(QString::number(pin_s31));
    ui->label_s32_state->setText(QString::number(pin_s32));

    ui->label_t2_w->setText(QString::number(ui->toolButton_tanque2->width()));
    ui->label_t2_h->setText(QString::number(ui->toolButton_tanque2->height()));
    ui->label_t3_w->setText(QString::number(ui->toolButton_tanque3->width()));
    ui->label_t3_h->setText(QString::number(ui->toolButton_tanque3->height()));

    ui->label_extra1->setText(QString::number(t2_to_t3_proportion));

    ui->toolButton_b1->setPower(pin_b1);
    ui->toolButton_sb11->setPower(pin_sb11);
    ui->toolButton_sb12->setPower(pin_sb12);
    ui->label_b1_state->setText(QString::number(temp));

    ui->toolButton_b1->setPower(pin_b1);
}

void MainWindow::processo_fisico(){

    pin_s21 = (tanque2>Sx1Threshold);
    pin_s22 = (tanque2>Sx2Threshold);

    pin_s31 = (tanque3>Sx1Threshold);
    pin_s32 = (tanque3>Sx2Threshold);

    if(freeze) return;

    if(pin_b1){
        temp += boilerTempIncrease;
    }else{
        temp -= boilerTempDecay;
    }

    if(pin_v1){
        tanque1 += valve1FlowRate;
        forceWaterLimit(tanque1);
    }

    if(pin_pump){
        tanque1 -= pumpFlowRate;
        tanque2 += pumpFlowRate;
        forceWaterLimit(tanque1);
    }

    if(pin_v2) {
        // t2 -> t3
        if (tanque2 > tanque3 / 2) {
            tanque2 -= t2_to_t3_transfer;
            tanque3 += t2_to_t3_transfer * t2_to_t3_proportion;
            forceWaterLimit(tanque3);
            // t3 -> t2
        } else {
            tanque2 += t2_to_t3_transfer;
            tanque3 -= t2_to_t3_transfer * t2_to_t3_proportion;
            forceWaterLimit(tanque2);
        }
    }

    if(tanque1 > 0 + vaporizationRate) // Evaporação
        tanque1 -= vaporizationRate;

    if(tanque2 > 0 + vaporizationRate) // Evaporação
        tanque2 -= vaporizationRate;

    // sensores

    pin_s11 = (tanque1>Sx1Threshold);
    pin_s12 = (tanque1>Sx2Threshold);

    pin_s21 = (tanque2>Sx1Threshold);
    pin_s22 = (tanque2>Sx2Threshold);

    pin_s31 = (tanque3>Sx1Threshold);
    pin_s32 = (tanque3>Sx2Threshold);

    pin_sb11 = temp > SBx1Threshold;
    pin_sb12 = temp > SBx2Threshold;
}
