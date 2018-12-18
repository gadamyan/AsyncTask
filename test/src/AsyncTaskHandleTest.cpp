
#include "MockTask.hpp"
#include "AsyncTaskHandle.hpp"

#include <gtest/gtest.h>

using namespace async_task;

struct AsyncTaskHandleFixture : public ::testing::Test
{
    MockTask* task;
    AsyncTaskHandle handle;

    AsyncTaskHandleFixture()
    : task(new MockTask())
    , handle(std::unique_ptr<MockTask>(task))
    {
    }
};

TEST_F(AsyncTaskHandleFixture, validate_task_type_id)
{
    ASSERT_EQ(handle.get_type_id(), "MockTask");
}

TEST_F(AsyncTaskHandleFixture, validate_task_initialization)
{
    ASSERT_EQ(handle.get_state(), TaskState::RUNNING);
}

TEST_F(AsyncTaskHandleFixture, validate_task_paused_state)
{
    handle.pause();
    ASSERT_EQ(handle.get_state(), TaskState::PAUSED);
    handle.pause();
    ASSERT_EQ(handle.get_state(), TaskState::PAUSED);
}

TEST_F(AsyncTaskHandleFixture, validate_task_resume_after_pause)
{
    handle.pause();
    ASSERT_EQ(handle.get_state(), TaskState::PAUSED);
    handle.resume();
    ASSERT_EQ(handle.get_state(), TaskState::RUNNING);
}

TEST_F(AsyncTaskHandleFixture, validate_task_cancel_after_pause)
{
    handle.pause();
    ASSERT_EQ(handle.get_state(), TaskState::PAUSED);
    handle.cancel();
    ASSERT_EQ(handle.get_state(), TaskState::CANCELLED);
}

TEST_F(AsyncTaskHandleFixture, validate_task_cancelled_state)
{
    handle.cancel();
    ASSERT_EQ(handle.get_state(), TaskState::CANCELLED);
    handle.cancel();
    ASSERT_EQ(handle.get_state(), TaskState::CANCELLED);
    handle.resume();
    ASSERT_EQ(handle.get_state(), TaskState::CANCELLED);
    handle.pause();
    ASSERT_EQ(handle.get_state(), TaskState::CANCELLED);
}

TEST_F(AsyncTaskHandleFixture, validate_task_completed_state)
{
    task->finish();
    while (handle.get_state() != TaskState::COMPLETED);
    ASSERT_EQ(handle.get_state(), TaskState::COMPLETED);
    handle.cancel();
    ASSERT_EQ(handle.get_state(), TaskState::COMPLETED);
    handle.resume();
    ASSERT_EQ(handle.get_state(), TaskState::COMPLETED);
    handle.pause();
    ASSERT_EQ(handle.get_state(), TaskState::COMPLETED);
}

TEST_F(AsyncTaskHandleFixture, task_resume_after_pause_regression_test)
{
    for (int i = 0; i < 1000; ++i)
    {
        handle.pause();
        ASSERT_EQ(handle.get_state(), TaskState::PAUSED);
        handle.resume();
        ASSERT_EQ(handle.get_state(), TaskState::RUNNING);
    }
}
