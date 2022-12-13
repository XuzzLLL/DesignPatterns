//
// Author:   Xuzzl
// Time:     2022/12/08
// Describe: 饿汉单例模式
//
#ifndef SINGLETON_H
#define SINGLETON_H

#include <QObject>
#include <QDebug>

class EagerSingleton
{
public:
    static EagerSingleton *getInstance(){
        return instance;
    };
    static void delInstance(){
        if(instance != nullptr) {
            delete instance;
            instance = nullptr;
        }
    };

private:
    EagerSingleton(){
        qDebug() << "EagerSingleton Hello";
    };
    ~EagerSingleton(){
        // 私有化可以避免直接 delete s1,必须使用 delInstance
        qDebug() << "EagerSingleton Bye";
    };
    // static对象，可以保证对象只生成一次,并且是多线程安全
    static EagerSingleton *instance;
};

#endif // SINGLETON_H
