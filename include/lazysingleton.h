//
// Author:   Xuzzl
// Time:     2022/12/08
// Describe: 懒汉单例模式 - 两种
//
#ifndef LAZYSINGLETON_H
#define LAZYSINGLETON_H

#include <QObject>
#include <QDebug>
#include <QMutex>

// 检查锁模式
class LazySingleton : public QObject
{
    Q_OBJECT
public:
    static LazySingleton *getInstance();
    static void delInstance();

private:
    LazySingleton();
    ~LazySingleton();
    LazySingleton(const LazySingleton &other); //拷贝构造函数
    LazySingleton &operator = (const LazySingleton &other); //赋值运算操作符

    // static对象，可以保证对象只生成一次
    static LazySingleton *instance;
    static QMutex m_mutex;
};

// static变量模式
class LazySingleton2 {
public:
    static LazySingleton2 *getInstance();

private:
    LazySingleton2();;
    ~LazySingleton2();
};

#endif // LAZYSINGLETON_H
