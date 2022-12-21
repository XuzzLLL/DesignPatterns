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

void MainWindow::on_ProtoType_clicked()
{
//    /// 用于复用的初始邮件创建
//    auto *originalMail = new ConcretePrototypeMail("original_title","original_sender","original_rec","original_body","original_attachment");
//    qDebug() << "originalMail address: "<< originalMail;
//    originalMail->showMail();
//    /// 浅拷贝
//    qDebug() << "====浅拷贝====";
//    auto *copyMail_A = originalMail;
//    copyMail_A->changeTitle("copymail_title");
//    copyMail_A->changeSender("copymail_sender");
//    copyMail_A->changeRecipients("copymail_rec");
//    copyMail_A->changeBody("copymail_body");
//    copyMail_A->changeAtt("copymail_attachment");
//    qDebug() << "====copyMail_A====";
//    qDebug() << "copyMail_A address: "<< copyMail_A;
//    copyMail_A->showMail();
//    qDebug() << "====originalMail====";
//    originalMail->showMail();
//    delete originalMail;

    /// 用于复用的初始邮件创建
    auto *originalMail = new ConcretePrototypeMail("original_title","original_sender","original_rec","original_body");
    originalMail->changeAtt("original_attachment");
    qDebug() << "originalMail address: "<< originalMail;
    originalMail->showMail();
    /// 深拷贝
    qDebug() << "====深拷贝====";
    auto *copyMail_A = originalMail->clone();
    copyMail_A->changeTitle("copymail_title");
    copyMail_A->changeSender("copymail_sender");
    copyMail_A->changeRecipients("copymail_rec");
    copyMail_A->changeBody("copymail_body");
    copyMail_A->changeAtt("copymail_attachment");
    qDebug() << "====copyMail_A====";
    qDebug() << "copyMail_A address: "<< copyMail_A;
    copyMail_A->showMail();
    qDebug() << "====originalMail====";
    originalMail->showMail();
    delete originalMail;
    delete copyMail_A;
}


void MainWindow::on_BuilderPattern_clicked()
{
    //指挥者
    Director director;
    //抽象建造者
    AbstractBuilder *builder;
    //产品：套餐
    ProductMeal *meal;

    //指定具体建造者A
    builder = new ConcreteBuilderMeal_A();
    director.setBuilder(builder);
    meal = director.construct();
    meal->showMeal();
    delete builder;
    qDebug() << "======================";
    //指定具体建造者C
    builder = new ConcreteBuilderMeal_C();
    director.setBuilder(builder);
    meal = director.construct();
    meal->showMeal();
    delete builder;
    qDebug() << "======================";
    //指定具体建造者B
    builder = new ConcreteBuilderMeal_B();
    director.setBuilder(builder);
    meal = director.construct();
    meal->showMeal();
    delete builder;

}


void MainWindow::on_ProxyPattern_clicked()
{
    Subject *subject;
    subject = new ProxySubject();
    subject->business();
    delete subject;
}

