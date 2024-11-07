#include "matrix.h"
#include <cstddef>
#include <stdexcept>
#include <iostream>
int** create(size_t rows, size_t cols)
{
  int** matrix = new int*[rows];
  size_t created = 0;
  try
  {
    for (; created < rows; ++created)
    {
      matrix[created] = new int[cols];
    }
  }
  catch(const std::bad_alloc& e) {
    destroy(matrix, created);
    throw;
  }
  return matrix;
}
void copy_matrix(int const* const* const mtx_old, int* const* const matrix, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < cols; j++)
    {
        matrix[i][j] = mtx_old[i][j];
    }
  }
}
void destroy(int** matrix, size_t rows)
{
  for (size_t i = 0; i < rows; i++)
  {
    delete[] matrix[i];
  }
  delete[] matrix;
}
void input(int** matrix, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < cols; j++)
    {
      std::cin >> matrix[i][j];
    }
  }
  if (!std::cin.good())
  {
    destroy(matrix, rows);
    throw std::logic_error("Error input");
  }
}
void print(const int* const* const matrix, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows; i++)
  {
    std::cout << matrix[i][0];
    for (size_t j = 1; j < cols; j++)
    {
      std::cout << " " << matrix[i][j];
    }
    std::cout << "\n";
  }
}
void initialize(int* const* const matrix, size_t rows, size_t cols, int init_num)
{
  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < cols; j++)
    {
        matrix[i][j] = init_num;
    }
  }
}
int** change_size(int** matrix, size_t rows, size_t cols, size_t new_rows, size_t new_cols)
{
  if (rows == new_rows && cols == new_cols)
  {
    return matrix;
  }
  size_t min_rows = std::min(rows, new_rows);
  size_t min_cols = std::min(cols, new_cols);
  int** new_matrix = create(new_rows, new_cols);
  initialize(new_matrix, new_rows, new_cols, 0);
  copy_matrix(matrix, new_matrix, min_rows, min_cols);
  destroy(matrix, rows);
  return new_matrix;
}

Matrix::Matrix(size_t rows, size_t cols):
  rows_(rows),
  cols_(cols),
  matrix_(::create(rows, cols))
{}
Matrix::Matrix(const Matrix& mtx_old):
  rows_(mtx_old.rows_),
  cols_(mtx_old.cols_),
  matrix_(::create(rows_, cols_))
{
  ::copy_matrix(mtx_old.matrix_, matrix_, rows_, cols_);
}
Matrix::~Matrix()
{
  ::destroy(matrix_, rows_);
}
void Matrix::input_()
{
  ::input(matrix_, rows_, cols_);
}
void Matrix::print_() const
{
  ::print(matrix_, rows_, cols_);
}
size_t Matrix::get_rows_() const
{
  return rows_;
}
size_t Matrix::get_cols_() const
{
  return cols_;
}
void Matrix::initialize_(int init_num)
{
  ::initialize(matrix_, rows_, cols_, init_num);
}
void Matrix::change_size_(int new_rows, int new_cols)
{
  matrix_ = ::change_size(matrix_, rows_, cols_, new_rows, new_cols);
  rows_ = new_rows;
  cols_ = new_cols;
}
