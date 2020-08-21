#include "gtest/gtest.h"
#include "core.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(core, basic) {
  ASSERT_EQ(0, 0);
}

TEST(core, print_msg) {
  Message say_hello("Hello, CMake World!");

  std::cout << say_hello << std::endl;

  Message say_goodbye("Goodbye, CMake World");

  std::cout << say_goodbye << std::endl;
  ASSERT_EQ(0, 0);
}
