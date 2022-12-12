//
// Author:   Xuzzl
// Time:     2022/12/12
// Describe: 工厂方法模式
//
#ifndef FACTORYMETHOD_H
#define FACTORYMETHOD_H

#include <QObject>
#include <QDebug>

///定义抽象产品类
class AbstractBallProduct
{
public:
    virtual ~AbstractBallProduct() = default;
    //抽象方法：
    virtual void productName() = 0;
    virtual void productIntroduction() = 0;
protected:
    AbstractBallProduct()= default;
};

///三个具体产品类
///具体产品类Basketball
class Basketball :public AbstractBallProduct
{
public:
    Basketball() = default;
    ~Basketball() override {
        qDebug() << "Basketball Bye";
    };
    void productName() override{
        qDebug() << "This is a Basketball";
    }
    void productIntroduction() override{
        qDebug() << "Introduction for Basketball";
    }
};

///具体产品类Football
class Football :public AbstractBallProduct
{
public:
    Football() = default;
    ~Football() override {
        qDebug() << "Football Bye";
    };
    void productName() override{
        qDebug() << "This is a Football";
    }
    void productIntroduction() override{
        qDebug() << "Introduction for Football";
    }
};

///具体产品类Volleyball
class Volleyball :public AbstractBallProduct
{
public:
    Volleyball() = default;
    ~Volleyball() override {
        qDebug() << "Volleyball Bye";
    };
    void productName() override{
        qDebug() << "This is a Volleyball";
    }
    void productIntroduction() override{
        qDebug() << "Introduction for Volleyball";
    }
};

/// 定义抽象工厂类
class AbstractFactory
{
public:
    virtual ~AbstractFactory() = default;
    virtual AbstractBallProduct * createProduct() = 0;
protected:
    AbstractFactory() = default;
};

///三个具体工厂类
///具体工厂类  只生产单一产品
class BasketballFactory : public AbstractFactory
{
public:
    BasketballFactory() = default;
    ~BasketballFactory() override {
        qDebug() << "BasketballFactory Bye";
    };
    AbstractBallProduct *createProduct() override{
        return  new Basketball();
    }
};

///具体工厂类  只生产单一产品
class FootballFactory : public AbstractFactory
{
public:
    FootballFactory() = default;
    ~FootballFactory() override {
        qDebug() << "FootballFactory Bye";
    };
    AbstractBallProduct *createProduct() override{
        return  new Football();
    }
};
///具体工厂类  只生产单一产品
class VolleyballFactory : public AbstractFactory
{
public:
    VolleyballFactory() = default;
    ~VolleyballFactory() override {
        qDebug() << "VolleyballFactory Bye";
    };
    AbstractBallProduct *createProduct() override{
        return  new Volleyball();
    }
};

#endif // FACTORYMETHOD_H
