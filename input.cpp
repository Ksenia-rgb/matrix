#include "matx.h"

void input(int** t, size_t M, size_t N)
{
  for (size_t i = 0; i < M; i++)
  {
    for (size_t j = 0; i < N; j++)
    {
      std::cin >> t[i][j];
    }
  }
  if (!std::cin.good())
  {
    std::cerr << "Error input\n";
    destroy(t, M);
  }
}
