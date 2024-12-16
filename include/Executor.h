#pragma once
#include <string>

namespace adas {

struct Pose {
    int x;
    int y;
    char heading;

    bool operator==(const Pose& other) const {
        return x == other.x && y == other.y && heading == other.heading;
    }
};

class Executor {
public:
    // 纯虚函数，用于执行命令
    virtual void Execute(const std::string& command) noexcept = 0;
    // 查询当前位置和方向
    virtual Pose Query(void) const noexcept = 0;
    // 纯虚函数，用于移动
    virtual void Move() noexcept = 0;
    // 纯虚函数，用于左转
    virtual void TurnLeft() noexcept = 0;
    // 纯虚函数，用于右转
    virtual void TurnRight() noexcept = 0;
    // 纯虚函数，用于加速
    virtual void Fast() noexcept = 0;
    // 纯虚函数，用于倒车
    virtual void Reverse() noexcept = 0;

    // 虚析构函数以确保派生类的析构函数被调用
    virtual ~Executor() = default;


};

}  // namespace adas