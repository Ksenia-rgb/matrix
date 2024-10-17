#include "mtx.h"
void destroy(int** t, size_t M, size_t N)
{
  for (size_t i = 0; i < M; i++)
  {
    delete[] t[i];
  }
  delete[] t;
}
