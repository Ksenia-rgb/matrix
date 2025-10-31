#ifndef MATRIX_H
#define MATRIX_H
#include <cstddef>
#include <stdexcept>

struct Matrix
{
  Matrix();
  Matrix(size_t rows, size_t cols);
  Matrix(const Matrix& mtx_old);
  Matrix(Matrix&& mtx_old);
  Matrix& operator=(const Matrix& mtx_old);
  Matrix& operator=(Matrix&& mtx_old);
  ~Matrix();

  void input();
  void print() const;
  size_t getRows() const;
  size_t getCols() const;
  void initialize(int init_num);
  void changeSize(int new_rows, int new_cols);
  void swap(Matrix& mtx);
private:
  size_t rows_, cols_;
  int** matrix_;
};

int** create(size_t rows, size_t cols);
void copy(int const* const* const mtx_old, int* const* const matrix, size_t rows, size_t cols);
void destroy(int** matrix, size_t rows);
void input(int* const* const matrix, size_t rows, size_t cols);
void print(const int* const* matrix, size_t rows, size_t cols);
void initialize(int* const* const matrix, size_t rows, size_t cols, int init_num);
int** changeSize(int** matrix, size_t rows, size_t cols, size_t new_rows, size_t new_cols);
#endif
