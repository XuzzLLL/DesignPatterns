//
// Author:   Xuzzl
// Time:     2022/12/21
// Describe: 建造者模式
//
#ifndef BUILDERPATTERN_H
#define BUILDERPATTERN_H

#include <QObject>
#include <QDebug>
#include <iostream>
#include <assert.h>

/// 产品角色（Product）
class ProductMeal
{
public:
    ProductMeal() {
        qDebug() << "ProductMeal Hello";
    };
    ~ProductMeal() {
        qDebug() << "ProductMeal Bye";
    };
    void setBurger(const std::string &iburger) {
        mBurger = iburger;
    }
    void setDrink(const std::string &idrink) {
        mDrink = idrink;
    }
    void setSnacks(const std::string &isnacks) {
        mSnacks = isnacks;
    }
    void showMeal(){
        qDebug() << "Burger is " << QString::fromStdString(mBurger);
        qDebug() << "Drink is " << QString::fromStdString(mDrink);
        qDebug() << "Snacks is " << QString::fromStdString(mSnacks);
    }

private:
    std::string mBurger;
    std::string mDrink;
    std::string mSnacks;
};


/// 抽象建造者（AbstractBuilder）
class AbstractBuilder
{
public:
    virtual ~AbstractBuilder() = default;
    //抽象方法：
    virtual void buildBurger() = 0;
    virtual void buildDrink() = 0;
    virtual void buildSnacks() = 0;
    virtual ProductMeal* getMeal() = 0;
protected:
    AbstractBuilder()= default;
};

/// 具体建造者（ConcreteBuilder）
class ConcreteBuilderMeal_A : public AbstractBuilder{ /// 套餐A
public:
    ConcreteBuilderMeal_A(){
        qDebug() << "ConcreteBuilderMeal_A Hello";
        meal = new ProductMeal();
    }
    ~ConcreteBuilderMeal_A() override{
        qDebug() << "ConcreteBuilderMeal_A Bye";
        delete meal;
    }
    void buildBurger() override {
        meal->setBurger("Veg Burger");
    };
    void buildDrink() override {
        meal->setDrink("coke");
    }
    void buildSnacks() override {
        meal->setSnacks("French fries");
    }
    ProductMeal* getMeal() override {
        return meal;
    }
private:
    ProductMeal *meal;
};

class ConcreteBuilderMeal_B : public AbstractBuilder{ /// 套餐B
public:
    ConcreteBuilderMeal_B(){
        qDebug() << "ConcreteBuilderMeal_B Hello";
        meal = new ProductMeal();
    }
    ~ConcreteBuilderMeal_B() override{
        qDebug() << "ConcreteBuilderMeal_B Bye";
        delete meal;
    }
    void buildBurger() override {
        meal->setBurger("Chicken Burger");
    };
    void buildDrink() override {
        meal->setDrink("pepsi");
    }
    void buildSnacks() override {
        meal->setSnacks("Onion rings");
    }
    ProductMeal* getMeal() override {
        return meal;
    }
private:
    ProductMeal *meal;
};
class ConcreteBuilderMeal_C : public AbstractBuilder{ /// 套餐C
public:
    ConcreteBuilderMeal_C(){
        qDebug() << "ConcreteBuilderMeal_C Hello";
        meal = new ProductMeal();
    }
    ~ConcreteBuilderMeal_C() override{
        qDebug() << "ConcreteBuilderMeal_C Bye";
        delete meal;
    }
    void buildBurger() override {
        meal->setBurger("Veg Burger");
    };
    void buildDrink() override {
        meal->setDrink("cafe");
    }
    void buildSnacks() override {
        meal->setSnacks("French fries");
    }
    ProductMeal* getMeal() override {
        return meal;
    }
private:
    ProductMeal *meal;
};

/// 指挥者（Director）
class Director
{
public:
    Director() {
        qDebug() << "Director Hello";
    };
    ~Director() {
        qDebug() << "Director Bye";
    }
    //具体实现方法
    void setBuilder(AbstractBuilder *iBuilder){
        this->builder = iBuilder;
    }
    //封装组装流程，返回建造结果
    ProductMeal *construct(){
        assert(builder!= nullptr);
        builder->buildBurger(); /// 制作顺序
        builder->buildDrink();
        builder->buildSnacks();
        return builder->getMeal();
    }
private:
    AbstractBuilder *builder= nullptr;
};

#endif // BUILDERPATTERN_H
