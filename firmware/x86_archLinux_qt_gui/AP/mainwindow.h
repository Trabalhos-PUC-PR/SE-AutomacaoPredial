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
    void teste1();
    void teste2();
    void teste3();
    void teste4();
    void teste5();
    void teste6();
};
#endif // MAINWINDOW_H
