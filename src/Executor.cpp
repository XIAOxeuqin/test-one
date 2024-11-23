#include "Executor.h"
namespace adas
{
// 类的声明在adas空间作用域内，因此在实现类的成员时，要使用空间作用域解析符
// 在函数声明时，已经明确了默认参数，因此在实现时，无需加上默认值

bool operator ==(const Pose& A, const Pose& B) {
    return (A.x == B.x) && (A.y == B.y) && (A.heading == B.heading);
}

// 构造
Executor* Executor::NewExecutor(const Pose &my_pose) {
    auto* p = new Executor();
    p->pose = my_pose;
    return p;
}
// 转向
void Executor::Execute(const std::string& command){
    for(int i=0; command[i]!='\0'; i++){
        if (command[i] == 'M') {
            switch (this->pose.heading) {
            case 'N':
                this->pose.y++;
                break;
            case 'E':
                this->pose.x++;
                break;
            case 'S':
                this->pose.y--;
                break;
            case 'W':
                this->pose.x--;
                break;
            default:
                break;
            }
        }
        else if (command[i] == 'L'){
            TurnLeft();
        }
        else if (command[i] == 'R'){
            TurnRight();
        }
        else {
            std::cout << "command is illegal" << std::endl;
        }
    }
}
Pose Executor::Query() {
    //std::cout<<"("<<this->pose.x<<","<<this->pose.y<<","<<this->pose.heading<<")"<<std::endl;
    return this->pose;
}

void Executor::TurnLeft() {
    switch (this->pose.heading) {
    case 'N': this->pose.heading = 'W'; break;
    case 'E': this->pose.heading = 'N'; break;
    case 'S': this->pose.heading = 'E'; break;
    case 'W': this->pose.heading = 'S'; break;
    default: break;
    }
}

void Executor::TurnRight() {
    switch (this->pose.heading) {
    case 'N': this->pose.heading = 'E'; break;
    case 'E': this->pose.heading = 'S'; break;
    case 'S': this->pose.heading = 'W'; break;
    case 'W': this->pose.heading = 'N'; break;
    default: break;
    }
}
}
//
// Created by DELL on 2024/11/23.
//
