//
// Author:   Xuzzl
// Time:     2022/12/21
// Describe: 观察者模式
//
#ifndef OBSERVERPATTERN_H
#define OBSERVERPATTERN_H

#include <QObject>
#include <QDebug>
#include <iostream>
#include <list>

/// Observer（观察者）:  Observer
class Observer {
public:
    virtual ~Observer() = default;
    virtual void update() = 0;
protected:
    Observer() = default;
};

/// Subject（目标）： Blog
class Blog {
public:
    virtual ~Blog() = default;
    void attach(Observer *observer) { //添加观察者
        observerList.push_back(observer);
    }
    void remove(Observer *observer) { //移除观察者
        observerList.remove(observer);
    }
    void notify() { //通知观察者
        for(auto observer:observerList) {
            observer->update();
        }
    }
    virtual void setStatus(QString s) = 0;
    virtual QString getStatus() = 0;   //获得状态
private:
    std::list<Observer* > observerList; //观察者链表
protected:
    Blog() = default;
    QString status; //状态
};

///ConcreteObserver（具体观察者）： ObserverBlog
class ObserverBlog : public Observer {
public:
    explicit ObserverBlog(const QString &name,Blog *blog) {
        this->name = name;
        this->blog = blog;
        qDebug() << "ObserverBlog Hello,name = " << this->name;
    }
    ~ObserverBlog() override {
        qDebug() << "ObserverBlog Bye,name = " << this->name;
    }

    void update() override{ //获得更新状态
        QString status = blog->getStatus();
        qDebug() << this->name << "-------" << status;
    }

private:
    QString name;  //观察者名称
    Blog *blog;
};

/// ConcreteSubject（具体目标）:  BlogCSDN
class BlogCSDN : public Blog
{
public:
    explicit BlogCSDN(const QString &name) {
        this->name = name;
        qDebug() << "BlogCSDN Hello,name = " << this->name;
    }
    ~BlogCSDN() override {
        qDebug() << "BlogCSDN Bye,name = " << this->name;
    }
    void setStatus(QString s) override {  //具体设置状态信息
        status = "CSDN通知 : " + name + s;
    }
    QString getStatus() override {
        return status;
    }

private:
    QString name; //博主名称
};

#endif // OBSERVERPATTERN_H
