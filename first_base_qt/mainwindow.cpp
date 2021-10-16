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

    // slider
    ui->horizontalSlider->setMinimum(0);
    ui->horizontalSlider->setMaximum(20);

    // progressBar
    ui->progressBar->setRange(0, 20);
    ui->progressBar->setValue(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked(bool checked)
{
    ui->pushButton->setText("hi, qzc");
    qDebug() << "hi, qzc " << checked;

    ui->label->setText("label : qzc");
    ui->checkBox->setChecked(true);
}
void MainWindow::clicked_method1(bool checked)
{
    ui->pushButton->setText("hi, qzc method1");
    qDebug() << "hi, qzc method1 " << checked;
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    //    bool is_check = ui->checkBox->isChecked();
    qDebug() << "hi, qzc, checkBox  is " << arg1;
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    qDebug() << "hi, qzc, slider " << value;
    ui->label_slider_value->setText(QString::number(value));

    ui->progressBar->setValue(value);
}



