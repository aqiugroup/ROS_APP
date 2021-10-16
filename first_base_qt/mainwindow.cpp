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

    // treeWidget
    ui->treeWidget->setHeaderLabels(QStringList()<<"key"<<"value");
    QTreeWidgetItem* item1 = new QTreeWidgetItem(QStringList()<<"Global Options");
    ui->treeWidget->addTopLevelItem(item1);
    item1->setIcon(0, QIcon("://images/options.png"));

    QTreeWidgetItem* item1_child = new QTreeWidgetItem(QStringList()<<"Fixed Frame");
    item1->addChild(item1_child);

    QComboBox* box1 = new QComboBox;
    box1->setMaximumWidth(160);
    box1->addItem("map");
    box1->setEditable(true);
    ui->treeWidget->setItemWidget(item1_child, 1, box1);
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


void MainWindow::slot_close_and_open(int)
{
    this->show();
}

void MainWindow::on_open_new_widget_btn_clicked()
{
    Form* f = new Form;
    f->show();

    connect(f, SIGNAL(close_and_open(int)), this, SLOT(slot_close_and_open(int)));
    this->hide();
}
