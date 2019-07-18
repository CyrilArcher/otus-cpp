#include "version.h"
#include <gtest/gtest.h>

TEST(ProjectVersionTest, GreaterThenZero) {
    ASSERT_GT(PROJECT_VERSION, 0);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}