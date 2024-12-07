#include "ExecutorImpl.h"

namespace adas {

char directions[4] = {'N', 'E', 'S', 'W'};
std::map<char, int> directions2index = {{'N', 0}, {'E', 1}, {'S', 2}, {'W', 3}};


Pose ExecutorImpl::Query() const noexcept {
    return m_Pose;
}


Executor* Executor::NewExecutor(const Pose& pose) noexcept {
     ExecutorImpl* p=new (std::nothrow) ExecutorImpl(pose);
    p->index=directions2index[pose.heading];
    return p;
    //InitIndex(ExecutorImpl* &p ,const Pose & pose);
}

ExecutorImpl::ExecutorImpl(const Pose& pose) noexcept : m_Pose(pose) {}

void ExecutorImpl::Execute(const std::string& commands) noexcept {
    for (const auto cmd : commands) {
        if (cmd == 'M') {
            Move();
        } else if (cmd == 'L') {
            TurnLeft();
        } else if (cmd == 'R') {
            TurnRight();
        } else if (cmd == 'F') {
            Fast();
        }
    }
}



void ExecutorImpl::Move() noexcept {
    if (IsFast()) {
        // Move twice if in fast mode
        if (m_Pose.heading == 'E') {
            m_Pose.x += 2;
        } else if (m_Pose.heading == 'W') {
            m_Pose.x -= 2;
        } else if (m_Pose.heading == 'N') {
            m_Pose.y += 2;
        } else if (m_Pose.heading == 'S') {
            m_Pose.y -= 2;
        }
    } else {
        if (m_Pose.heading == 'E') {
            m_Pose.x++;
        } else if (m_Pose.heading == 'W') {
            m_Pose.x--;
        } else if (m_Pose.heading == 'N') {
            m_Pose.y++;
        } else if (m_Pose.heading == 'S') {
            m_Pose.y--;
        }
    }
}

void ExecutorImpl::TurnLeft() noexcept {
    // Turn left logic here
    if(isFast) {
        Fast();
        Move();
    }
    index = (index - 1 + 4) % 4;
    m_Pose.heading = directions[index];
}

void ExecutorImpl::TurnRight() noexcept {
    // Turn right logic here
    if(isFast) {
        Fast();
        Move();
    }
    index = (index + 1) % 4;
    m_Pose.heading = directions[index];
}

void ExecutorImpl::Fast() noexcept {
    isFast = !isFast;
}

bool ExecutorImpl::IsFast() const noexcept {
    return isFast;
}



}  // namespace adas//
// Created by DELL on 2024/12/7.
//
