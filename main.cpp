#include <iostream>
#include "matx.h"

int main()
{
  size_t M = 0, N = 0;
  std::cin >> M >> N;
  if (!std::cin.good() || M <= 0 || N <= 0)
  {
    std::cerr << "Error input\n";
  }
  else
  {
    try
    {
      int** table = create(M, N);
      input(table, M, N);
      output(table, M, N);
      destroy(table, M);
    }
    catch(const std::bad_alloc &e)
    {
      std::cerr << e.what() << "\n";
    }
  }
}
