#ifndef MATRIX_H
#define MATRIX_H
#include <cstddef>
#include <stdexcept>
struct Matrix
{
  Matrix(size_t rows, size_t cols);
  Matrix(const Matrix& mtx_old);
  ~Matrix();
  void input_();
  void print_() const;
  size_t get_rows_() const;
  size_t get_cols_() const;
  void initialize_(int init_num);
  void change_size_(int new_rows, int new_cols);
private:
  size_t rows_, cols_;
  int** matrix_;
};
int** create(size_t rows, size_t cols);
void copy_matrix(int const* const* const mtx_old, int* const* const matrix, size_t rows, size_t cols);
void destroy(int** matrix, size_t rows);
void input(int** matrix, size_t rows, size_t cols);
void print(const int* const* matrix, size_t rows, size_t cols);
void initialize(int* const* const matrix, size_t rows, size_t cols, int init_num);
int** change_size(int** matrix, size_t rows, size_t cols, size_t new_rows, size_t new_cols);
#endif
