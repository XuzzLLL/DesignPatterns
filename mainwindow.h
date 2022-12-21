#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "eagersingleton.h"
#include "lazysingleton.h"
#include "factorymethod.h"
#include "simplefactory.h"
#include "abstractfactory.h"
#include "prototype.h"
#include "builderpattern.h"
#include "proxypattern.h"

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
    void on_EagerSingleton_clicked();

    void on_LazySingleton_clicked();

    void on_FactoryMethod_clicked();

    void on_SimpleFactory_clicked();

    void on_AbstractFactory_clicked();

    void on_ProtoType_clicked();

    void on_BuilderPattern_clicked();

    void on_ProxyPattern_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
