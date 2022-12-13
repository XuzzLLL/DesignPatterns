//
// Author:   Xuzzl
// Time:     2022/12/13
// Describe: 简单工厂模式
//
#ifndef SIMPLEFACTORY_H
#define SIMPLEFACTORY_H

#include <QObject>
#include <QDebug>

///定义抽象产品类
class AbstractSimpleBallProduct
{
public:
    virtual ~AbstractSimpleBallProduct() = default;
    //抽象方法：
    virtual void productName() = 0;
    virtual void productIntroduction() = 0;
protected:
    AbstractSimpleBallProduct()= default;

};

//三个具体产品类
//具体产品类Basketball
class SimpleBasketball :public AbstractSimpleBallProduct
{
public:
    SimpleBasketball() = default;
    ~SimpleBasketball() override {
        qDebug() << "Basketball Bye";
    };
    void productName() override{
        qDebug() << "This is a Basketball";
    }
    void productIntroduction() override{
        qDebug() << "Introduction for Basketball";
    }
};

//具体产品类Football
class SimpleFootball :public AbstractSimpleBallProduct
{
public:
    SimpleFootball() = default;
    ~SimpleFootball() override {
        qDebug() << "Football Bye";
    };
    void productName() override{
        qDebug() << "This is a Football";
    }
    void productIntroduction() override{
        qDebug() << "Introduction for Football";
    }
};

//具体产品类Volleyball
class SimpleVolleyball :public AbstractSimpleBallProduct
{
public:
    SimpleVolleyball() = default;
    ~SimpleVolleyball() override {
        qDebug() << "Volleyball Bye";
    };
    void productName() override{
        qDebug() << "This is a Volleyball";
    }
    void productIntroduction() override{
        qDebug() << "Introduction for Volleyball";
    }
};

/// 定义工厂类和工厂方法
class SimpleFactory
{
public:
    static AbstractSimpleBallProduct *getProduct(const std::string& productName)
    {
        AbstractSimpleBallProduct *pro = nullptr;
        if (productName == "Basketball"){
            pro = new SimpleBasketball();
        }
        else if (productName == "Football"){
            pro = new SimpleFootball();
        }
        else if (productName == "Volleyball"){
            pro = new SimpleVolleyball();
        }
        return pro;
    }
};

#endif // SIMPLEFACTORY_H
