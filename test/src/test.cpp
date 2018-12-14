#include "test.hpp"
#include "core.hpp"

#include <gtest/gtest.h>

const char* foo()
{
    return ""; //bar();
}

TEST(aaa, bbb)
{
    ASSERT_TRUE(1 == 1);
}
