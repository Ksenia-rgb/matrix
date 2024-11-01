#include <iostream>
#include "matrix.h"
int main()
{
  size_t rows = 0, cols = 0;
  std::cin >> rows >> cols;
  if (!std::cin.good() || rows <= 0 || cols <= 0)
  {
    std::cerr << "Error input\n";
    return 1;
  }
  Matrix mtx(rows, cols);
  mtx.initialize_(0);
  mtx.print_();
}
