#include <iostream>
#include <stdexcept>
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
    /*Matrix mtx(rows, cols);
    mtx.input();
    mtx.print();

    size_t new_rows = 0, new_cols = 0;
    std::cin >> new_rows >> new_cols;
    mtx.changeSize(new_rows, new_cols);
    mtx.print();*/

    int** matrix = create(rows, cols);
    input(matrix, rows, cols);
    print(matrix, rows, cols);
    int** trans_matrix = transpose(matrix, rows, cols);
    print(trans_matrix, cols, rows);
    destroy(matrix, rows);
    destroy(trans_matrix, cols);

    int row_matrix[] = {1, 1, 1, 2, 2, 3, 3, 3, 3, 4};
    size_t size = 10;
    size_t lns[] = {3, 2, 4, 1};
    size_t rows = 4;
    int** table_matrix = convert(row_matrix, size, lns, rows);
    print(table_matrix, lns, rows);
    destroy(table_matrix, rows);
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "ERROR: Memory not allocated for array\n";
    return 2;
  }
  catch (const std::logic_error& e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
}
