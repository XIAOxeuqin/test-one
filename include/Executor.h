#pragma once
#include <string>
#include<map>
namespace adas {

struct Pose {
    int x;
    int y;
    char heading;

    bool operator==(const Pose& other) const {
        return x == other.x && y == other.y && heading == other.heading;
    }
};
extern char directions[4];
extern std::map<char, int> directions2index;
class Executor {
public:
    static Executor* NewExecutor(const Pose& pose = {0, 0, 'N'}) noexcept;
    Executor(void) = default;
    virtual ~Executor(void) = default;
    Executor(const Executor&) = delete;
    Executor& operator=(const Executor&) = delete;
    virtual void Execute(const std::string& command) noexcept = 0;
    virtual Pose Query(void) const noexcept = 0;
    virtual void Move()=0;
    virtual void TurnLeft()=0;
    virtual void TurnRight()=0;
    virtual void Fast()=0;

private:
    Pose m_Pose{};

public:
    int index=0;
};

class ICommand {
public:
    virtual ~ICommand() = default;
    virtual void DoOperate(Executor& executor) const noexcept = 0;
};

}  // namespace adas//
// Created by DELL on 2024/12/7.
//

#ifndef EXECUTOR_H
#define EXECUTOR_H

#endif //EXECUTOR_H
