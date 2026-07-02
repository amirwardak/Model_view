#include "mainwindow.h"
#include "mymodel.h"
#include "mymodeladress.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QDebug>
#include <QMessageBox>

template <typename T>
void readFile(const QString& filename, QVector<T>& data){
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly)){
        qDebug() << "Can't open file \"" << filename << "\"!";
        return;
    }
    QTextStream input(&file);
    while(!input.atEnd()){
        T temp;
        input >> temp;
        data.push_back(temp);
    }
    file.close();
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , model(nullptr) // изначально делаем модель пустой
    , modelAdress(nullptr)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_load_from_txt_clicked()
{

    ui->statusbar->showMessage("Loading...", 2000);
    const QString filePath = QFileDialog::getOpenFileName(this, "Open file", "", "Text file (*.txt)");
    if(filePath.isEmpty()) {
        ui->statusbar->showMessage("Loading canceled", 3000);
        return;
    }
    readFile(filePath, externalData);
    if(!model){
        model = new MyModel(&externalData, this);
    }

    model->resetModel(); // модели надо дать понять что мы переделываем данные
    ui->statusbar->showMessage(QString("Finished loading %1 records").arg(externalData.size()), 5000);
}


void MainWindow::on_btnShow_clicked()
{
    activeType = DataType::Telephon;
    if(model){
        ui->tableView->setModel(model);
        ui->tableView->setEnabled(true);
        ui->tableView->resizeColumnsToContents();

        ui->tableView->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::EditKeyPressed);
    }
}

void MainWindow::on_actionSaveAs_triggered(){
    if(activeType == DataType::Telephon){
        SaveCurrentData(externalData, "WithTelephons");
    }
    else if(activeType == DataType::Adress){
        SaveCurrentData(extDataAdress, "WithAdress");
    }
}

void MainWindow::on_btnLoadAdress_clicked()
{

    ui->statusbar->showMessage("Loading...", 2000);
    const QString filePath = QFileDialog::getOpenFileName(this, "Open file", "", "Text file (*.txt)");
    if(filePath.isEmpty()) {
        ui->statusbar->showMessage("Loading canceled", 3000);
        return;
    }
    readFile(filePath, extDataAdress);
    if(!modelAdress){
        modelAdress = new MyModelAdress(&extDataAdress, this);
    }

    modelAdress->resetModel(); // модели надо дать понять что мы переделываем данные
    ui->statusbar->showMessage(QString("Finished loading %1 records").arg(extDataAdress.size()), 5000);
}


void MainWindow::on_btnShowAdress_clicked()
{
    activeType = DataType::Adress;
    if(modelAdress){
        ui->tableView->setModel(modelAdress);
        ui->tableView->setEnabled(true);
        ui->tableView->resizeColumnsToContents();
        ui->tableView->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::EditKeyPressed);
    }
}

