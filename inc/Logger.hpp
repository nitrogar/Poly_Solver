#ifndef LOGGER_HEADER
#define LOGGER_HEADER
#include <cstdlib>
#include <format>
#include <iostream>
#include <map>
#include <string>
#include <vector>

class Logger {
public:
  Logger(){};
  template <class... Args> void log(Args... msg) const {
    (std::cout << ... << msg) << std::endl;
  };

  template <class... Args> void panic(Args... msg) const {
    std::cout << "[PANIC!!]";
    (std::cout << ... << msg) << std::endl;
    exit(0);
  };
};
#endif
