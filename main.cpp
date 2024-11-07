#include <iostream>
#include "matrix.h"
int main()
{
  size_t rows = 0, cols = 0;
  std::cin >> rows >> cols;
  if (!std::cin.good())
  {
    std::cerr << "Error input\n";
    return 1;
  }
  try
  {
    Matrix mtx(rows, cols);
    mtx.input_();
    mtx.print_();
    size_t new_rows = 0, new_cols = 0;
    std::cin >> new_rows >> new_cols;
    mtx.change_size_(new_rows, new_cols);
    mtx.print_();
    Matrix mtx1(mtx);
    mtx1.print_();
  }
  catch(const std::bad_alloc& e)
  {
    std::cerr << "ERROR: Memory not allocated for array\n";
    return 1;
  }
  catch (const std::logic_error& e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
}
