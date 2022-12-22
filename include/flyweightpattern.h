//
// Author:   Xuzzl
// Time:     2022/12/22
// Describe: 享元模式
//
#ifndef FLYWEIGHTPATTERN_H
#define FLYWEIGHTPATTERN_H

#include <QObject>
#include <QDebug>
#include <iostream>
#include <map>
#include <vector>

/// UnsharedConcreteFlyweight（非共享具体享元类）：Coordinates
class Coordinates {
public:
    Coordinates(int x,int y) {
        this->x = x;
        this->y = y;
        qDebug() << "Coordinates Hello, x = " << x << " y = " << y;
    }
    ~Coordinates() {
        qDebug() << "Coordinates Bye, x = " << x << " y = " << y;
    }
    int getX() {
        return x;
    }
    void setX(int x) {
        this->x = x;
    }
    int getY() {
        return y;
    }
    void setY(int y) {
        this->y = y;
    }
private:
    int x;
    int y;
};

/// Flyweight（抽象享元类）：ChessPiece
class ChessPiece {
public:
    virtual ~ChessPiece() = default;
    virtual QString getColor() = 0;
    void display(Coordinates *coord) {
        qDebug() << "棋子颜色：" << getColor() << "，棋子位置："
                 << "x = " << coord->getX() << "，y = " << coord->getY();
    };
protected:
    ChessPiece() = default;
    QString color;
};

/// ConcreteFlyweight（具体享元类）：BlackChessPiece  WhiteChessPiece
class BlackChessPiece : public ChessPiece {
public:
    BlackChessPiece() {
        qDebug() << "BlackChessPiece Hello";
        color = "黑色";
    }
    ~BlackChessPiece() override {
            qDebug() << "BlackChessPiece Bye";
    }
    QString getColor() override{
        return color;
    }
};

class WhiteChessPiece : public ChessPiece {
public:
    WhiteChessPiece() {
        qDebug() << "WhiteChessPiece Hello";
        color = "白色";
    }
    ~WhiteChessPiece() override {
        qDebug() << "WhiteChessPiece Bye";
    }
    QString getColor() override{
        return color;
    }
};

/// FlyweightFactory（享元工厂类）：ChessPieceFactory
class ChessPieceFactory {
public:
    static ChessPieceFactory *getInstance() {
        static ChessPieceFactory instance;
        return &instance;
    }
    ChessPiece *getChessPiece(const QString& color) {
        return mapChessPiece[color];
    }
private:
    ChessPieceFactory() {
        qDebug() << "ChessPieceFactory Hello";
        mapChessPiece.insert(std::pair<QString,ChessPiece *>("b",new BlackChessPiece()));
        mapChessPiece.insert(std::pair<QString,ChessPiece *>("w",new WhiteChessPiece()));
    }
    ~ChessPieceFactory() {
        qDebug() << "ChessPieceFactory Bye";
        auto  iter = mapChessPiece.begin();
        while(iter!=mapChessPiece.end()) {
            ChessPiece *chessPiece = iter->second;
            delete chessPiece;
            iter++;
        }
    }
    std::map<QString,ChessPiece *> mapChessPiece;
};


#endif // FLYWEIGHTPATTERN_H
