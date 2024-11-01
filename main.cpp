#include <iostream>
#include "matrix.h"
int main()
{
  size_t M = 0, N = 0;
  std::cin >> M >> N;
  if (!std::cin.good() || M <= 0 || N <= 0)
  {
    std::cerr << "Error input\n";
    return 1;
  }
  int** table = create(M, N);
  input(table, M, N);
  print(table, M, N);
  destroy(table, M);
}
