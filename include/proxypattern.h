//
// Author:   Xuzzl
// Time:     2022/12/21
// Describe: 代理模式
//
#ifndef PROXYPATTERN_H
#define PROXYPATTERN_H

#include <QObject>
#include <QDebug>
#include <iostream>
#include <ctime>
#pragma execution_character_set("utf-8")

/// Subject（抽象主题角色）： Subject
class Subject {
public:
    virtual ~Subject() = default;
    virtual void business() = 0;
protected:
    Subject() = default;
};

/// RealSubject（真实主题角色）： RealSubject
class RealSubject : public Subject {
public:
    RealSubject (){
        qDebug() << "RealSubject Hello";
    }
    ~RealSubject () override{
        qDebug() << "RealSubject Bye";
    }
    void business() override{
        qDebug() << "business 业务代码在此执行";
    }
};

/// 附加功能： Log
class Log {
public:
    Log () {
        qDebug() << "Log Hello";
    }
    ~Log () {
        qDebug() << "Log Bye";
    }
    std::string addTimeLog() {
        time_t t = time(nullptr);
        char timeLog[64] = {0};
        std::strftime(timeLog, 63, "%Y-%m-%d %H:%M:%S",localtime(&t));
        return std::string(timeLog);
    }
};

/// Proxy（代理主题角色）：ProxySubject
class ProxySubject : public Subject {
public:
    ProxySubject (){
        qDebug() << "ProxySubject Hello";
        realSubject = new RealSubject();
        log = new Log();
    }
    ~ProxySubject () override{
        qDebug() << "ProxySubject Bye";
        delete realSubject;
        delete log;
    }
    void preBusiness() {
        qDebug() << "preBusiness 被调用，时间为：" << QString::fromStdString(log->addTimeLog());
    }
    void business() override {
        preBusiness();
        realSubject->business();
        afterBusiness();
    }
    void afterBusiness() {
        qDebug() << "afterBusiness 被调用，时间为：" << QString::fromStdString(log->addTimeLog());
    }
private:
    RealSubject *realSubject;
    Log *log;
};

#endif // PROXYPATTERN_H
