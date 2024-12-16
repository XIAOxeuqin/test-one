#pragma once
#include "Executor.h"

namespace adas {

class PoseHandler {
public:
    explicit PoseHandler(const Pose& pose) noexcept;
    Pose Query() const noexcept;
    void Move() noexcept;
    void TurnLeft() noexcept;
    void TurnRight() noexcept;
    void Fast() noexcept;
    void Reverse() noexcept;
    bool IsFast() const noexcept;
    bool IsReverse() const noexcept;

private:
    Pose m_Pose;
    bool isFast{false};
    bool isReverse{false};
    int index=0;
};

}  // namespace adas