#include <gtest/gtest.h>
#include "Executor.h"
#include"ExecutorImpl.h"
#include"ICommand.h"
namespace adas {

TEST(ExecutorFastTest, should_return_x_plus_2_given_status_is_fast_command_is_M_and_facing_is_E) {
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

    // when
    executor->Execute("FM");

    // then
    const Pose target{2, 0, 'E'};
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorFastTest, should_return_N_and_x_plus_1_given_status_is_fast_command_is_L_and_facing_is_E) {
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

    // when
    executor->Execute("FL");

    // then
    const Pose target{1, 0, 'N'};
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorFastTest, should_return_S_and_x_plus_1_given_status_is_fast_given_command_is_R_and_facing_is_E) {
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

    // when
    executor->Execute("FR");

    // then
    const Pose target{1, 0, 'S'};
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorFastTest, should_return_E_plus_1_given_command_is_FFM_and_facing_is_E) {
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

    // when
    executor->Execute("FFM");

    // then
    const Pose target{1, 0, 'E'};
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorFastTest, should_return_S_plus_1_given_command_is_FM_and_facing_is_S) {
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'}));

    // when
    executor->Execute("FM");

    // then
    const Pose target{0, -2, 'S'};
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorFastTest, should_return_y_plus_1_given_command_is_FFM_and_facing_is_N) {
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}));

    // when
    executor->Execute("FR");

    // then
    const Pose target{-1, 0, 'N'};
    ASSERT_EQ(target, executor->Query());
}

}  // namespace adas
// Created by DELL on 2024/12/7.
//
//
// Created by DELL on 2024/12/7.
//
