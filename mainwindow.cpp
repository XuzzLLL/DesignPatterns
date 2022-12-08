#include "mainwindow.h"
#include "./ui_mainwindow.h"

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

void MainWindow::on_EagerSingleton_clicked()
{
    EagerSingleton *s1 = EagerSingleton::getInstance();
    EagerSingleton *s2 = EagerSingleton::getInstance();

    qDebug() << "s1 address = " << s1;
    qDebug() << "s2 address = " << s2;

    EagerSingleton::delInstance();
}

void MainWindow::on_LazySingleton_clicked()
{
    LazySingleton *s1 = LazySingleton::getInstance();
    LazySingleton *s2 = LazySingleton::getInstance();

    qDebug() << "s1 address = " << s1;
    qDebug() << "s2 address = " << s2;

    LazySingleton::delInstance();

    LazySingleton2 *s3 = LazySingleton2::getInstance();
    LazySingleton2 *s4 = LazySingleton2::getInstance();

    qDebug() << "s3 address = " << s3;
    qDebug() << "s4 address = " << s4;
}



