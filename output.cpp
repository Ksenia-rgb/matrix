#include "matx.h"
void (int** t, size_t M, size_t N)
{
  for (size_t i = 0; i < M; i++)
  {
    std::cout << t[i][0];
    for (size_t j = 1; j < N; j++)
    {
      std::cout << " " << t[i][j];
    }
    std::cout << "\n";
  }
}
