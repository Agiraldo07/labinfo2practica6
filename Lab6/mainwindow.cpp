#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    h=ui->graphicsView->height();

    h_limit = ui->graphicsView->width()-2;
    v_limit = ui->graphicsView->height()-2;
    dt = 1.0;


    apagar_todo();

    ui->planetas->setEnabled(true);
    ui->Agregar->setEnabled(true);



    timer = new QTimer(this);
    scene = new QGraphicsScene(this);
    scene->setSceneRect(-h_limit/2,-v_limit/2,h_limit,v_limit); // Añadir la tmño de la escena

    ui->graphicsView->setScene(scene);
    ui->graphicsView->scale(0.5,0.5);
    ui->centralwidget->adjustSize();
    ui->num->display(contp);


    timer->stop();
    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));

}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
    delete timer;
    for (int i=0;i<bars.size() ;i++ ) {
        delete bars[i];
    }

}

void MainWindow::actualizar()
{
    for (int i=0;i<bars.size() ;i++ ) {
        bars.at(i)->getEsf()->ini_aceleraciones();
        for (int j=0;j<bars.size() ;j++ ) {
            if(i!=j){
                bars.at(i)->getEsf()->acelerar(bars.at(j)->getEsf()->getPX(),
                                               bars.at(j)->getEsf()->getPY(),
                                               bars.at(j)->getEsf()->getMasa());
                bars.at(i)->actualizar(1.0);

            }
        }

    }
}

void MainWindow::apagar_todo()
{
    ui->vyo->setEnabled(false);
    ui->vxo->setEnabled(false);
    ui->yo->setEnabled(false);
    ui->xo->setEnabled(false);
    ui->iniciar->setEnabled(false);
    ui->parar->setEnabled(false);
    ui->Agregar->setEnabled(false);
    ui->planetas->setEnabled(false);
    ui->masa->setEnabled(false);
    ui->radio->setEnabled(false);
    ui->pausa->setEnabled(false);
}


void MainWindow::on_Agregar_clicked()
{

    if (ui->planetas->value() >= 2){
        N_planeta = ui->planetas->value();
        apagar_todo();
        ui->vyo->setEnabled(true);
        ui->vxo->setEnabled(true);
        ui->yo->setEnabled(true);
        ui->xo->setEnabled(true);
        ui->masa->setEnabled(true);
        ui->radio->setEnabled(true);
        ui->Agregar->setEnabled(true);
        ui->planetas->setValue(0);
    }

    else  if (N_planeta != 0){
        ui->num->display(contp+1);
        bars.append(new Grafica(ui->xo->value(),ui->yo->value(),ui->vxo->value(),ui->vyo->value(),ui->masa->value(),ui->radio->value()));
        contp ++;
        if (contp == N_planeta){//label en que planeta vas
            apagar_todo();
            ui->iniciar->setEnabled(true);
        }
    }

}


void MainWindow::on_iniciar_clicked() //ejecutar simulacion
{

    for (int i=0;i<bars.size() ;i++ ) {
        bars.at(i)->actualizar(dt);
        scene->addItem(bars.at(i));
    }

    ui->parar->setEnabled(true);
    ui->iniciar->setEnabled(false);
    ui->pausa->setEnabled(true);
    timer->start(dt);
    //zoom();
}


void MainWindow::on_parar_clicked()
{
    ui->parar->setEnabled(false);
    ui->Agregar->setEnabled(true);
    timer->stop();
    n=0;
    contp =0;
    for (int i=0;i<bars.size() ;i++ ) {
        scene->removeItem(bars.at(i));
    }
}

void MainWindow::on_pausa_clicked()
{
    ui->parar->setEnabled(false);
    ui->Agregar->setEnabled(false);
    ui->iniciar->setEnabled(true);

    timer->stop();

}
