#include "matx.h"
void destroy(int** t, size_t M)
{
  for (size_t i = 0; i < M; i++)
  {
    delete[] t[i];
  }
  delete[] t;
}
