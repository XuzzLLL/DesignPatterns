#include "eagersingleton.h"

// 饿汉模式的关键：初始化即实例化
EagerSingleton *EagerSingleton::instance = new EagerSingleton();

EagerSingleton::EagerSingleton()
{
    qDebug() << "EagerSingleton Hello";
}

EagerSingleton::~EagerSingleton()
{
    // 私有化可以避免直接 delete s1,必须使用 delInstance
    qDebug() << "EagerSingleton Bye";
}

EagerSingleton *EagerSingleton::getInstance()
{
    return instance;
}

void EagerSingleton::delInstance()
{
    if(instance != nullptr) {
        delete instance;
        instance = nullptr;
    }
}
