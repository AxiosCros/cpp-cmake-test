#include <cstdlib>
#include <iostream>

#include "core.hpp"
// #include <curlpp/Easy.hpp>
// #include <curlpp/Options.hpp>
// #include <curlpp/cURLpp.hpp>

int main() {
  Message say_hello("Hello, CMake World!");

  std::cout << say_hello << std::endl;

  Message say_goodbye("Goodbye, CMake World");

  std::cout << say_goodbye << std::endl;
  return EXIT_SUCCESS;
}
