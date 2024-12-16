#include "ExecutorImpl.h"

namespace adas {

ExecutorImpl::ExecutorImpl(const Pose& pose) noexcept
    : m_PoseHandler(pose) {
    // 初始化命令映射表
    m_CommandMap
        = {
            {'M', [this]() { m_PoseHandler.Move(); }},
            {'L', [this]() { m_PoseHandler.TurnLeft(); }},
            {'R', [this]() { m_PoseHandler.TurnRight(); }},
            {'F', [this]() { m_PoseHandler.Fast(); }},
            {'B', [this]() { m_PoseHandler.Reverse(); }}
        };
}

void ExecutorImpl::Execute(const std::string& command) noexcept {
    for (const auto cmd : command) {
        const auto it = m_CommandMap.find(cmd);
        if (it != m_CommandMap.end()) {
            it->second();  // 执行找到的命令
        }
    }
}

Pose ExecutorImpl::Query(void) const noexcept {
    return m_PoseHandler.Query();
}

void ExecutorImpl::Move() noexcept {
    m_PoseHandler.Move();
}

void ExecutorImpl::TurnLeft() noexcept {
    m_PoseHandler.TurnLeft();
}

void ExecutorImpl::TurnRight() noexcept {
    m_PoseHandler.TurnRight();
}

void ExecutorImpl::Fast() noexcept {
    m_PoseHandler.Fast();
}

void ExecutorImpl::Reverse() noexcept {
    m_PoseHandler.Reverse();
}

}    // namespace adas