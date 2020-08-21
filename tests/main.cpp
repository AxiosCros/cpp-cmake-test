#include "core.hpp"
#include "gtest/gtest.h"

#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/cURLpp.hpp>

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(core, basic) { ASSERT_EQ(0, 0); }

TEST(core, print_msg) {
  Message say_hello("Hello, CMake World!");

  std::cout << say_hello << std::endl;

  Message say_goodbye("Goodbye, CMake World");

  std::cout << say_goodbye << std::endl;
  ASSERT_EQ(0, 0);
}

TEST(core, curlpp) {
  #ifdef CURLPP_CURL_HANDLE_HPP
  try {
    curlpp::Cleanup myCleanup;

    curlpp::options::Url myUrl(std::string("http://example.com"));
    curlpp::Easy myRequest;
    myRequest.setOpt(myUrl);
    myRequest.perform();

    std::ostringstream os;
    curlpp::options::WriteStream ws(&os);
    myRequest.setOpt(ws);
    myRequest.perform();

    os << myRequest;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
  #else
  std::cout << "required curlpp failed" << std::endl;
  #endif
}
