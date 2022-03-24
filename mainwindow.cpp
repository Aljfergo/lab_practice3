#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "visualizadorimagenes.h"
#include "ruidogaussiano.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_botonVI_clicked()
{
    vi = new VisualizadorImagenes();
    vi->setVisible(true);
}

void MainWindow::on_botonAl_clicked()
{
    rg = new RuidoGaussiano();
    rg->exec();
}

void MainWindow::on_EjecucionImages_clicked()
{
    for(int i=0; i<vi->executionTime.size();i++){
        ui->tExVI->setText(ui->tExVI->text()+"\n *"+QString::number(vi->executionTime[i])+"ms");

    }
}

