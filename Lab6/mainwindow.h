#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "pelota.h"
#include <string>
#include <QTimer>
#include "cuerpo.h"
#include "grafica.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void apagar_todo();

private slots:
    void actualizar();
    void on_Agregar_clicked();
    void on_iniciar_clicked();
    void on_parar_clicked();
    void on_pausa_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QGraphicsScene *scene;

    float xo,yo,vxo,vyo,g;
    int T=1, h; //Tiempo de discretizacion (Calcular valor ecuaciones)
    unsigned long long n=0;
    float dt;
    float entrada;

    int h_limit;
    int v_limit;


    int N_planeta = 0; //Número de planetas
    QList<Grafica*> bars;
    int contp =0;


};
#endif // MAINWINDOW_H
