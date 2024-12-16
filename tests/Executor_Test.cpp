#include <gtest/gtest.h>
#include "ExecutorImpl.h"
#include "PoseHandler.h"
#include<memory>

namespace adas {

class ExecutorImplTest : public ::testing::Test {
protected:
    std::unique_ptr<ExecutorImpl> executor;  // 使用智能指针来管理资源
    Pose initialPose{0, 0, 'N'};

    void SetUp() override {
        executor = std::make_unique<ExecutorImpl>(initialPose);  // 使用智能指针初始化executor
    }
};

TEST_F(ExecutorImplTest, MovesCorrectly) {
    executor->Execute("M");
    EXPECT_EQ(executor->Query().x, 0);
    EXPECT_EQ(executor->Query().y, 1);
    EXPECT_EQ(executor->Query().heading, 'N');
}

TEST_F(ExecutorImplTest, TurnsLeftCorrectly) {
    executor->Execute("L");
    EXPECT_EQ(executor->Query().heading, 'W');
}

TEST_F(ExecutorImplTest, TurnsRightCorrectly) {
    executor->Execute("R");
    EXPECT_EQ(executor->Query().heading, 'E');
}

TEST_F(ExecutorImplTest, FastModeMovesFurther) {
    executor->Execute("FM");
    EXPECT_EQ(executor->Query().x, 0);  // Assuming fast mode moves twice the distance
    EXPECT_EQ(executor->Query().y, 2);
    EXPECT_EQ(executor->Query().heading, 'N');
}

TEST_F(ExecutorImplTest, ReverseModeChangesBehavior) {
    executor->Execute("B");
    executor->Execute("M");
    EXPECT_EQ(executor->Query().y, -1);  // Assuming reverse moves in the opposite direction
    EXPECT_EQ(executor->Query().heading, 'N');
}

TEST_F(ExecutorImplTest, CombinationOfCommands) {
    executor->Execute("FLR");
    EXPECT_EQ(executor->Query().x, -1);  // Fast forward, then right turn, should move one step to the east
    EXPECT_EQ(executor->Query().y, 1);
    EXPECT_EQ(executor->Query().heading, 'N');
}

}  // namespace adas