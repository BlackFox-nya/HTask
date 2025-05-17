#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QMessageBox"
#include "QFileDialog"

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


void MainWindow::on_pushButton_clicked()
{
    int day, stday, dayOfWeek;
    stday = 4;
    bool chk;
    chk = true;
    day = ui->lineEdit->text().toInt();
    if (day < 1 || day > 365){
        QMessageBox::warning(this, "ERROR!", "Input is out of range, range is [1; 365]");
        chk = false;
    }
    if (chk){
        dayOfWeek = (stday + (day - 1)) % 7;
        QString days[]{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        ui->res->setNum(dayOfWeek);
        ui->resname->setText(days[dayOfWeek]);
    }
}


void MainWindow::on_actionSave_triggered()
{
    //збереження у файл
    QString filePath = QFileDialog::getSaveFileName(this, "Save file",
                                                    QDir::currentPath(), "Текстові файли (*.txt);;Усі файли (*)");
    if (!filePath.isEmpty()) {
        QFile file(filePath);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QMessageBox::critical(nullptr, "Error",
                                  "Can not open file:\n" + file.errorString());
        }
        else {
            QTextStream out(&file);
            out << ui->res->text();
            out << "  -  ";
            out << ui->resname->text();
            file.close();
        }
    }
    else {
        QMessageBox::warning(0, "Error", "Unknown filename!");
    }
}


void MainWindow::on_actionLoad_triggered()
{
    //зчитування з файлу
    QString filePath = QFileDialog::getOpenFileName(this, "Open file",
                                                    QDir::currentPath(), "Текстові файли (*.txt);;Усі файли (*)");
    if (!filePath.isEmpty()) {
        QFile file(filePath);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QMessageBox::warning(0, "Error", "Can not open file!");
        }
        else {
            QTextStream in(&file);
            QString sa;
            in >> sa;
            ui->lineEdit->setText(sa);
            file.close();
        }
    }
    else {
        QMessageBox::warning(0, "Error", "Unknown filename!");
    }
}

