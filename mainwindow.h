#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <ruidogaussiano.h>
#include <visualizadorimagenes.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    RuidoGaussiano* rg;
    VisualizadorImagenes* vi;
private slots:
    void on_botonVI_clicked();

    void on_botonAl_clicked();

    void on_EjecucionImages_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
