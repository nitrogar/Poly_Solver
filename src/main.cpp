#include<iostream>
#include <Poly.hpp>

int main() {

  std::cout << "Hello, world!" << std::endl;
  Poly fx(10);
  Poly fz(10);

  Poly fy = fx + fz;
  std::cout << "far awya" << std::endl;
  std::cout << fy.to_string() << std::endl;
  return 0;
}
