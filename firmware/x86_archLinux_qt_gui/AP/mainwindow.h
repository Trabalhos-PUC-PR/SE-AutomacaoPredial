#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "threadbehavior.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QTimer timer_ui;
    QTimer timer_processo_fisico;
    ThreadBehavior tb;

private:
    Ui::MainWindow *ui;

public slots:
    void atualiza_interface();
    void processo_fisico();
    void drainT2();
    void drainT3();
    void congela();
    void add5_to_T1();
    void add5_to_T2();
    void add5_to_T3();
    void remove5_from_T1();
    void remove5_from_T2();
    void remove5_from_T3();
};
#endif // MAINWINDOW_H
