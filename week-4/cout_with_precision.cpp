#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

void PrintNumbers(const std::string &path) {
  std::ifstream input(path);
  double number;

  if (input) {
    std::cout << std::fixed << std::setprecision(3);
    while (input >> number) {
      std::cout << number << std::endl;
    }
  }
}