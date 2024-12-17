#pragma once         //当编译器读取该文件时，会记录该文件已经被包含；从而下次再读取时，不会重新读取；防止头文件被多次包含，简化代码，避免重复定义和编译错误
#include <string>
#include<iostream>
namespace adas       //namespace//：组织代码并防止命名冲突，使代码更易于管理和阅读
{
struct Pose {
    int x;           // 定义结构体
    int y;
    char heading;
};

bool  operator ==(const Pose& poseA,const Pose& poseB) ;

class Executor    //抽象类，提供接口定义，隐藏功能实现细节
{
public:

    static Executor* NewExecutor(const Pose& myPose = {0, 0,'N'});
    //
    static void InitIndex(Executor* &p ,const Pose & myPose);
    //默认构造函数
    Executor();
    //虚构函数
    virtual ~Executor(void)=default;

    Executor(const Executor&) = delete;

    Executor& operator=(const Executor&) = delete;
    //virtual: 关键字表示该函数是一个虚函数，允许在派生类中进行重写
    virtual void Execute(const std::string& commands);
    //查询
    virtual Pose Query();
    //左转
    virtual void TurnLeft();
    //右转
    virtual void TurnRight();
    //前进
    virtual void MoveForward();

private:
    Pose pose{};
    int index=0;
    char directions[4]={'N','E','S','W'};
};

}


//
// Created by DELL on 2024/12/16.
//

#ifndef CPP_TRAINING_EXECUTOR_H
#define CPP_TRAINING_EXECUTOR_H

#endif  // CPP_TRAINING_EXECUTOR_H
