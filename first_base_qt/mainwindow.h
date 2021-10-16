#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "form.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked(bool checked);
    void clicked_method1(bool checked);

    void on_checkBox_stateChanged(int arg1);

    void on_horizontalSlider_valueChanged(int value);

    void on_open_new_widget_btn_clicked();
    void slot_close_and_open(int);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
