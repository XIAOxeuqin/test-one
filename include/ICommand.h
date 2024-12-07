#pragma once
#include"Executor.h"

namespace adas
{
class MoveCommand final : public ICommand {
public:
    void DoOperate(Executor& executor) const noexcept override {
        static_cast<ExecutorImpl&>(executor).Move();  //将传入的Executor引用转换为ExecutorImpl类型的引用，并调用这个转换后的引用的Move方法
    }
};


class TurnLeftCommand final : public ICommand {
public:
    void DoOperate(Executor& executor) const noexcept override {
        static_cast<ExecutorImpl&>(executor).TurnLeft();
    }
};

class TurnRightCommand final : public ICommand {
public:
    void DoOperate(Executor& executor) const noexcept override {
        static_cast<ExecutorImpl&>(executor).TurnRight();
    }
};

class FastCommand final : public ICommand {
public:
    void DoOperate(Executor& executor) const noexcept override {
        static_cast<ExecutorImpl&>(executor).Fast();
    }
};
}

//
// Created by DELL on 2024/12/7.
//

#ifndef ICOMMAND_H
#define ICOMMAND_H

#endif //ICOMMAND_H
//
// Created by DELL on 2024/12/7.
//

#ifndef ICOMMAND_H
#define ICOMMAND_H

#endif //ICOMMAND_H
