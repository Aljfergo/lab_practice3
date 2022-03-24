#ifndef VISUALIZADORIMAGENES_H
#define VISUALIZADORIMAGENES_H

#include <QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QLabel>
#include <QInputDialog>
#include <QMessageBox>
#include <QTime>

QT_BEGIN_NAMESPACE
namespace Ui { class VisualizadorImagenes; }
QT_END_NAMESPACE

class VisualizadorImagenes : public QMainWindow
{
    Q_OBJECT

public:
    VisualizadorImagenes(QWidget *parent = nullptr);
    ~VisualizadorImagenes();
    std::vector<float> executionTime;

private:

    Ui::VisualizadorImagenes *ui;

    QStringList imagenes;

    void mostrarImagenes();

    std::vector<QLabel*> labels;



private slots:

    void abrir_imagen();
    void  guardar_imagen();
    void guardarComo_imagen();

    void aplicarRuido();

};
#endif // VISUALIZADORIMAGENES_H
