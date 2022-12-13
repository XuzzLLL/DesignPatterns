#include "eagersingleton.h"

// 饿汉模式的关键：初始化即实例化
EagerSingleton *EagerSingleton::instance = new EagerSingleton();

