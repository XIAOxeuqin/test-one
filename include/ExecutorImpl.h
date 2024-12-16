#pragma once
#include "Executor.h"
#include "PoseHandler.h"
#include <unordered_map>
#include <functional>
#include <string>

namespace adas {

class ExecutorImpl final : public Executor {
public:
    explicit ExecutorImpl(const Pose& pose) noexcept;
    ~ExecutorImpl() noexcept override = default;
    ExecutorImpl(const ExecutorImpl&) = delete;
    ExecutorImpl& operator=(const ExecutorImpl&) = delete;

    void Execute(const std::string& command) noexcept override;
    Pose Query(void) const noexcept override;
    void Move() noexcept override;
    void TurnLeft() noexcept override;
    void TurnRight() noexcept override;
    void Fast() noexcept override;
    void Reverse() noexcept override;


private:
    PoseHandler m_PoseHandler;
    std::unordered_map<char, std::function<void()>> m_CommandMap;

};

}   // namespace adas