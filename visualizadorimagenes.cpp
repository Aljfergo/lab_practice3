#include "visualizadorimagenes.h"
#include "ui_visualizadorimagenes.h"

VisualizadorImagenes::VisualizadorImagenes(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VisualizadorImagenes)
{
    ui->setupUi(this);

    QMenu* menuAbrir = ui->menubar->addMenu("Archivo(s)");

    menuAbrir->addAction("Abrir...", this , SLOT(abrir_imagen()));
    menuAbrir->addAction("Guardar...", this , SLOT(guardar_imagen()));
    menuAbrir->addAction("Guardar como...", this , SLOT(guardarComo_imagen()));

    QMenu* menuEditar = ui->menubar->addMenu("Editar");

        QMenu* menuFiltros = menuEditar->addMenu("Filtros...");

        menuFiltros->addAction("Ruido Gaussiano", this , SLOT(aplicarRuido()));

    //menuAbrir->addAction("Guardar...", this , SLOT(abrir_imagen()));
    //menuAbrir->addAction("Guardar como...", this , SLOT(abrir_imagen()));

}

VisualizadorImagenes::~VisualizadorImagenes()
{
    delete ui;
}

void VisualizadorImagenes::abrir_imagen(){

    imagenes = QFileDialog::getOpenFileNames(this, "Escoge una o varias imagenes", "/home", "Images (*.jpg *.xpm *.png *.jpeg)");

    mostrarImagenes();

}


void VisualizadorImagenes::guardar_imagen(){
    QMessageBox::information(this,"Guardar","Tus imagenes seran guaradas");
    for (int i=0; i< imagenes.length(); i++){
        QImage image=labels[i]->pixmap()->toImage();
        image.save(imagenes[i]);
    }


}

void VisualizadorImagenes::guardarComo_imagen(){



    for(int i =0;i<imagenes.length();i++){
        QString imagePath = QFileDialog::getSaveFileName(this, tr("Guardar archivo"), "", tr("JPEG (*.jpg *.jpeg);;PNG (*.png)" ));
        QImage image=labels[i]->pixmap()->toImage();

        image.save(imagePath);
    }

}

void VisualizadorImagenes::mostrarImagenes(){

    for(int i = 0; i < imagenes.length(); i++){

        QLabel* label = new QLabel;

        label->setPixmap(QPixmap::fromImage(QImage(imagenes.at(i))));

        labels.push_back(label);

        ui->gridLayout->addWidget(label);

    }

}

void VisualizadorImagenes::aplicarRuido(){
    int ruido= QInputDialog::getInt(this, "Cantidad de ruido", "Ingrese un valor para el ruido gaussiano", 0, 0, 255,0);
    QTime myTimer;
    myTimer.start();

    for(int i = 0; i < imagenes.length(); i++){
        QImage image;

        bool valid =image.load(imagenes[i]);

        if(valid){
            QMessageBox::information(this,"Loading","Procesando");
            for(int i = 0; i< image.width(); i++){
                        for(int j = 0; j< image.height(); j++){
                            QColor color(image.pixel(i,j));


                            //Gauss
                            int gaussRojo= rand()%ruido-ruido/2;
                            int gaussVerde= rand()%ruido-ruido/2;
                            int gaussAzul= rand()%ruido-ruido/2;



                            //Rojo
                            if(color.red()+gaussRojo>255){
                                color.setRed(255);
                            }else if (color.red()+gaussRojo<0){
                                color.setRed(0);
                            }else{
                                color.setRed(color.red()+gaussRojo);
                            }



                            //Verde
                            if(color.green()+gaussVerde>255){
                                color.setGreen(255);
                            }else if(color.green()+gaussVerde<0){
                                color.setGreen(0);

                            }else{
                                color.setGreen(color.green()+gaussVerde);
                            }


                            //Azul
                            if(color.blue()+gaussAzul>255){
                                color.setBlue(255);
                            }else if (color.blue()+gaussAzul<0){
                                color.setBlue(0);
                            }else{
                                color.setBlue(color.blue()+gaussAzul);
                            }

                            image.setPixel(i,j,color.rgb());
                        }

            }
            //image = image.scaledToWidth(labels[i]->width());
            labels[i]->setPixmap(QPixmap::fromImage(image));

            //Sustituimos la imagen original el stack para poder continuar friendo la imagen



        }else{
            QMessageBox::warning(this,"Error","No se pudo cargar la imagen");;
        }
       int nMilliseconds = myTimer.elapsed();
        this->executionTime.push_back(nMilliseconds);

    }

}
