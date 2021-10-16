#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtDebug"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pushButton->setText("hello qt");
    // method 1: clicked_method1 (not use on_pushButton_clicked_method1 bcs it will bave warning)
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(clicked_method1(bool)));
    // method 2:
    // name slot method as : on_pushButton_clicked

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked(bool checked)
{
    ui->pushButton->setText("hi, qzc");
    qDebug() << "hi, qzc " << checked;
}
void MainWindow::clicked_method1(bool checked)
{
    ui->pushButton->setText("hi, qzc method1");
    qDebug() << "hi, qzc method1 " << checked;
}
