#pragma once
#include "Executor.h"

namespace adas
{
class ExecutorImpl final : public Executor {
public:
    explicit ExecutorImpl(const Pose& pose) noexcept;
    ~ExecutorImpl() noexcept override = default;
    //static void InitIndex(ExecutorImpl* &p ,const Pose & pose);
    ExecutorImpl(const ExecutorImpl&) = delete;
    ExecutorImpl& operator=(const ExecutorImpl&) = delete;

    void Execute(const std::string& command) noexcept override;
    Pose Query(void) const noexcept override;

private:
    Pose m_Pose;
    bool isFast{false};

public:
    void Move() noexcept override;
    void TurnLeft() noexcept override;
    void TurnRight() noexcept override;
    void Fast() noexcept override;
    bool IsFast() const noexcept;
};
}

//
// Created by DELL on 2024/12/7.
//

#ifndef EEXCUTORIMPL_H
#define EEXCUTORIMPL_H

#endif //EEXCUTORIMPL_H
