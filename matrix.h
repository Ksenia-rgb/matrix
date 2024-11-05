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
    int get_rows_() const;
    int get_cols_() const;
    void initialize_(int init_num);
    void change_size_(int new_rows, int new_cols);
private:
    size_t rows_, cols_;
    int** matrix_;
};
int** create(size_t M, size_t N);
void copy_matrix(int** mtx_old_, int** matrix_, size_t rows_, size_t cols_);
void destroy(int** table, size_t M);
void input(int** table, size_t M, size_t N);
void print(const int * const * table, size_t M, size_t N);
void initialize(int** matrix, size_t rows, size_t cols, int init_num);
int** change_size(int** matrix, size_t rows, size_t cols, size_t new_rows, size_t new_cols);
#endif
