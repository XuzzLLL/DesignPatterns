//
// Author:   Xuzzl
// Time:     2022/12/21
// Describe: 外观模式
//
#ifndef FACADEPATTERN_H
#define FACADEPATTERN_H

#include <QObject>
#include <QDebug>
#include <iostream>

/// SubSystem（子系统角色）：Motherboard、Memory、CPU、HardDisk、OS
//子系统：Motherboard
class Motherboard
{
public:
    Motherboard() {
        qDebug() << "Motherboard Hello";
    }
    ~Motherboard() {
        qDebug() << "Motherboard Bye";
    }
    void powerOnMotherboard(){
        qDebug() << "-----主板上电";
    }
};
//Memory
class Memory
{
public:
    Memory() {
        qDebug() << "Memory Hello";
    }
    ~Memory() {
        qDebug() << "Memory Bye";
    }
    void selfCheckMemory(){
        qDebug() << "-----内存自检电";
    }
};
//CPU
class CPU
{
public:
    CPU() {
        qDebug() << "CPU Hello";
    }
    ~CPU() {
        qDebug() << "CPU Bye";
    }
    void runCPU(){
        qDebug() << "-----CPU运行";
    }
};
//HardDisk
class HardDisk
{
public:
    HardDisk() {
        qDebug() << "HardDisk Hello";
    }
    ~HardDisk() {
        qDebug() << "HardDisk Bye";
    }
    void readHardDisk(){
        qDebug() << "-----读取硬盘";
    }
};
//OS
class OS
{
public:
    OS() {
        qDebug() << "OS Hello";
    }
    ~OS() {
        qDebug() << "OS Bye";
    }
    void loadOS(){
        qDebug() << "-----加载操作系统";
    }
};

/// Facade（外观角色）： PowerOnButton
class PowerOnButton {
public:
    PowerOnButton() {
        qDebug() << "PowerOnButton Hello";
        motherBoard = new Motherboard();
        memory = new Memory();
        cpu = new CPU();
        hardDisk = new HardDisk();
        os = new OS();
    }
    ~PowerOnButton() {
        delete os;
        delete hardDisk;
        delete cpu;
        delete memory;
        delete motherBoard;
        qDebug() << "PowerOnButton Bye";
    };
    void pressButton(){
        qDebug() << "Press PowerOn Button";
        qDebug() << "正在开机...";
        qDebug() << "....";
        qDebug() << "..";
        motherBoard->powerOnMotherboard();
        memory->selfCheckMemory();
        cpu->runCPU();
        hardDisk->readHardDisk();
        os->loadOS();
        printf("开机完成！\n");
    }
private:
    Motherboard *motherBoard = nullptr;
    Memory *memory = nullptr;
    CPU *cpu = nullptr;
    HardDisk *hardDisk = nullptr;
    OS *os = nullptr;

};

#endif // FACADEPATTERN_H
