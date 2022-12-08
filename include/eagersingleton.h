//
// Author:   Xuzzl
// Time:     2022/12/08
// Describe: 饿汉单例模式
//
#ifndef SINGLETON_H
#define SINGLETON_H

#include <QObject>
#include <QDebug>

class EagerSingleton : public QObject
{
    Q_OBJECT
public:
    static EagerSingleton *getInstance();
    static void delInstance();

private:
    EagerSingleton();;
    ~EagerSingleton();
    // static对象，可以保证对象只生成一次,并且是多线程安全
    static EagerSingleton *instance;
};


#endif // SINGLETON_H
