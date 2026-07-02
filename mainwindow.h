#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "mymodel.h"
#include "mymodeladress.h"

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QVector<WithTelephon> datas;
    MainWindow(QWidget *parent = nullptr);
    template <typename T>
    void SaveCurrentData(const QVector<T>& current, const QString& defaultFileName){
        if(current.isEmpty()){
            QMessageBox::warning(this, "Save as", "No data to save!");
            return;
        }

        QString filePath = QFileDialog::getSaveFileName(this, "Save as", defaultFileName, "Text files (*.txt)");
        if(filePath.isEmpty()) return;

        if(!filePath.endsWith(".txt", Qt::CaseInsensitive)) filePath += ".txt";

        QFile file(filePath);
        if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
            QMessageBox::critical(this, "Error", "Can't open file" + file.errorString());
            return;
        }

        QTextStream out(&file);
        for(const auto& el : current){
            out << el;
        }

        QMessageBox::information(this, "Success", "Data saved to:\n" + filePath);
    }
    ~MainWindow();

private slots:
    void on_load_from_txt_clicked();

    void on_btnShow_clicked();

    void on_actionSaveAs_triggered();

    void on_btnLoadAdress_clicked();

    void on_btnShowAdress_clicked();

private:
    Ui::MainWindow *ui;
    QVector<WithTelephon> externalData;
    QVector<WithAddres> extDataAdress;
    MyModel* model;
    MyModelAdress* modelAdress;
    enum class DataType{
        Telephon,
        Adress,
    };
    DataType activeType;
};
#endif // MAINWINDOW_H
