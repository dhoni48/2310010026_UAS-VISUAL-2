#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    uiUser = new user(this);
    uiUser->show();
}


void MainWindow::on_pushButton_2_clicked()
{
    uiCustomer = new customer(this);
    uiCustomer->show();
}


void MainWindow::on_pushButton_3_clicked()
{
    uiPermintaan = new permintaan(this);
    uiPermintaan->show();
}

