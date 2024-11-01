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
    for (;created < rows; ++created)
    {
      matrix[created] = new int[cols];
    }
  }
  catch(const std::bad_alloc& e) {
    destroy(matrix, created);
    std::cerr << "ERROR: Memory not allocated for array\n";
  }
  return matrix;
}
void copy_matrix(int const *const *const mtx_old_, int** matrix_, size_t rows_, size_t cols_)
{
  for (size_t i = 0; i < rows_; i++)
  {
    for (size_t j = 0; j < cols_; j++)
    {
        matrix_[i][j] = matrix_[i][j];
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
    for (size_t j = 0; i < cols; j++)
    {
      std::cin >> matrix[i][j];
    }
  }
  if (!std::cin.good())
  {
    std::cerr << "Error input\n";
    destroy(matrix, rows);
  }
}
void print(const int *const *const matrix, size_t rows, size_t cols)
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
void initialize(int *const *const matrix, size_t rows, size_t cols, int init_num)
{
  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < cols; j++)
    {
        matrix[i][j] = init_num;
    }
  }
}
void change_size(int** matrix, size_t rows, size_t cols, size_t new_rows, size_t new_cols)
{
  size_t min_rows = std::min_element(rows, new_rows);
  size_t min_cols = std::max_element(cols, new_cols);
  int** new_matrix = create(new_rows, new_cols);
  for (size_t i = 0; i < min_rows; i++)
  {
    for (size_t j = 0; j < min_cols; j++)
    {
      new_matrix[i][j] = matrix[i][j];
    }
  }
  destroy(matrix, rows);
  matrix = new_matrix;
}

Matrix::Matrix(size_t rows, size_t cols):
  rows_(rows),
  cols_(cols),
  matrix_(create(rows, cols))
{}
Matrix::Matrix(const Matrix& mtx_old):
  rows_(mtx_old.rows_),
  cols_(mtx_old.cols_),
  matrix_(create(rows_, cols_))
{
  copy_matrix(mtx_old.matrix_, matrix_, rows_, cols_);
}
Matrix::~Matrix()
{
  destroy(matrix_, rows_);
}
void Matrix::input_()
{
  input(matrix_, rows_, cols_);
}
void Matrix::print_()
{
  print(matrix_, rows_, cols_);
}
int Matrix::get_rows_()
{
  return rows_;
}
int Matrix::get_cols_()
{
  return cols_;
}
void Matrix::initialize_(int init_num)
{
  initialize(matrix_, rows_, cols_, init_num);
}
void Matrix::change_size_(int new_rows, int new_cols)
{
  change_size(matrix_, rows_, cols_, new_rows, new_cols);
}
