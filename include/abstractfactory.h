//
// Author:   Xuzzl
// Time:     2022/12/13
// Describe: 抽象工厂模式
//
#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include <QObject>
#include <QDebug>

///定义抽象产品类
class AbstractPhoneProduct
{
public:
    virtual ~AbstractPhoneProduct() = default;
    //抽象方法：
    virtual void productName() = 0;
    virtual void productIntroduction() = 0;
protected:
    AbstractPhoneProduct()= default;

};

///2个具体产品类
///具体产品类 HWPhone
class HWPhone :public AbstractPhoneProduct
{
public:
    HWPhone() = default;
    ~HWPhone() override {
        qDebug() << "HWPhone Bye";
    };
    void productName() override{
        qDebug() << "This is a HWPhone";
    }
    void productIntroduction() override{
        qDebug() << "Introduction for HWPhone";
    }
};

///具体产品类 MIPhone
class MIPhone :public AbstractPhoneProduct
{
public:
    MIPhone() = default;
    ~MIPhone() override {
        qDebug() << "MIPhone Bye";
    };
    void productName() override{
        qDebug() << "This is a MIPhone";
    }
    void productIntroduction() override{
        qDebug() << "Introduction for MIPhone";
    }
};


///定义抽象产品类
class AbstractTVProduct
{
public:
    virtual ~AbstractTVProduct() = default;
    //抽象方法：
    virtual void productName() = 0;
    virtual void productIntroduction() = 0;
protected:
    AbstractTVProduct()= default;

};

///2个具体产品类
///具体产品类 HWTV
class HWTV :public AbstractTVProduct
{
public:
    HWTV() = default;
    ~HWTV() override {
        qDebug() << "HWTV Bye";
    };
    void productName() override{
        qDebug() << "This is a HWTV";
    }
    void productIntroduction() override{
        qDebug() << "Introduction for HWTV";
    }
};

///具体产品类 MITV
class MITV :public AbstractTVProduct
{
public:
    MITV() = default;
    ~MITV() override {
        qDebug() << "MITV Bye";
    };
    void productName() override{
        qDebug() << "This is a MITV";
    }
    void productIntroduction() override{
        qDebug() << "Introduction for MITV";
    }
};


/// 定义抽象工厂类
class TheAbstractFactory
{
public:
    virtual ~TheAbstractFactory() = default;
    virtual AbstractPhoneProduct * createPhone() = 0;
    virtual AbstractTVProduct * createTV() = 0;
protected:
    TheAbstractFactory() = default;
};

///两个具体工厂类
///具体工厂类  生产多个产品
class HWFactory : public TheAbstractFactory
{
public:
    HWFactory() = default;
    ~HWFactory() override {
        qDebug() << "HWFactory Bye";
    };
    AbstractPhoneProduct *createPhone() override{
        return  new HWPhone();
    }
    AbstractTVProduct *createTV() override{
        return  new HWTV();
    }
};

///具体工厂类  生产多个产品
class MIFactory : public TheAbstractFactory
{
public:
    MIFactory() = default;
    ~MIFactory() override {
        qDebug() << "MIFactory Bye";
    };
    AbstractPhoneProduct *createPhone() override{
        return  new MIPhone();
    }
    AbstractTVProduct *createTV() override{
        return  new MITV();
    }
};
#endif // ABSTRACTFACTORY_H
