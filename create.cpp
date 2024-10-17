#include "matx.h"
int** create(size_t M, size_t N)
{
  int** t = new int*[M];
  size_t created = 0;
  try {
    for (;created < M; ++created)
    {
      t[created] = new int[N];
    }
  } catch(const std::bad_alloc &e) {
      destroy(t, created);
      throw;
  }
  return t;
}
