#include "gtest/gtest.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(core, basic) {
  ASSERT_EQ(0, 0);
}

TEST(core, basic2) {
  ASSERT_EQ(0, 0);
}
