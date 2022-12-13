#include "mainwindow.h"
#include "./ui_mainwindow.h"
#pragma execution_character_set("utf-8")

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
    qDebug() << "饿汉单例模式";
    EagerSingleton *s1 = EagerSingleton::getInstance();
    EagerSingleton *s2 = EagerSingleton::getInstance();

    qDebug() << "s1 address = " << s1;
    qDebug() << "s2 address = " << s2;

    EagerSingleton::delInstance();
}

void MainWindow::on_LazySingleton_clicked()
{
    qDebug() << "懒汉单例模式";
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

void MainWindow::on_FactoryMethod_clicked()
{
    qDebug() << "工厂方法模式";
    //定义工厂类对象和产品类对象
    AbstractBallProduct *product = nullptr;
    AbstractFactory *factory = nullptr;

    factory = new BasketballFactory();
    product = factory->createProduct();
    product->productName();
    delete factory;
    delete product;


    factory = new FootballFactory();
    product = factory->createProduct();
    product->productIntroduction();
    delete factory;
    delete product;

    factory = new VolleyballFactory();
    product = factory->createProduct();
    product->productIntroduction();
    delete factory;
    delete product;
}


void MainWindow::on_SimpleFactory_clicked()
{
    qDebug() << "简单工厂模式";
    //定义工厂类对象
    AbstractSimpleBallProduct *product = nullptr;
    product = SimpleFactory::getProduct("Basketball");
    product->productName();
    delete product;

    product = SimpleFactory::getProduct("Football");
    product->productIntroduction();
    delete product;

    product = SimpleFactory::getProduct("Volleyball");
    product->productIntroduction();
    delete product;
}


void MainWindow::on_AbstractFactory_clicked()
{
    qDebug() << "抽象工厂模式";

    //定义工厂类对象和产品类对象
    AbstractPhoneProduct *phone = nullptr;
    AbstractTVProduct *tv = nullptr;
    TheAbstractFactory *factory = nullptr;

    factory = new HWFactory();
    phone = factory->createPhone();
    phone->productName();
    tv = factory->createTV();
    tv->productIntroduction();
    delete factory;
    delete phone;
    delete tv;

    factory = new MIFactory();
    phone = factory->createPhone();
    phone->productName();
    tv = factory->createTV();
    tv->productIntroduction();
    delete factory;
    delete phone;
    delete tv;
}

