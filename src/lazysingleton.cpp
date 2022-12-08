#include "lazysingleton.h"

LazySingleton* LazySingleton::instance = nullptr;
QMutex LazySingleton::m_mutex;

LazySingleton *LazySingleton::getInstance() {
    //第一个检查，如果只是读操作，就不许用加锁
    if (instance == nullptr) {
        //std::lock_guard<std::mutex> lck(m_mutex);
        m_mutex.lock();
        //第二个检查，保证只有一个
        if (instance == nullptr) {
            instance = new LazySingleton();
        }
        m_mutex.unlock();
    }
    return instance;
}

void LazySingleton::delInstance() {
    if(instance != nullptr) {
        delete instance;
        instance = nullptr;
    }
}

LazySingleton::LazySingleton()
{
    qDebug() << "LazySingleton Hello";
}

LazySingleton::~LazySingleton()
{
    // 私有化 可以避免 直接 delete s1 ，必须 使用 delInstance
    qDebug() << "LazySingleton Bye";
}


LazySingleton2 *LazySingleton2::getInstance()
{
    static LazySingleton2 instance;
    return &instance;
}

LazySingleton2::LazySingleton2()
{
    qDebug() << "LazySingleton2 Hello";
}

LazySingleton2::~LazySingleton2()
{
    // 私有化 可以避免 直接 delete s1 ，必须 使用 delInstance
    qDebug() << "LazySingleton2 Bye";
}
