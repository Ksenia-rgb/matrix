#ifndef MTX_H
#define MTX_H
#include <cstddef>
int** create(size_t M, size_t N);
void destroy(int** table, size_t M);
void input (int** table, size_t M, size_t N);
void output(const int * const * table, size_t M, size_t N);

#endif
