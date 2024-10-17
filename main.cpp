#include <iostream>
#include "matx.h"

int main()
{
  size_t M = 0, N = 0;
  std::cin >> M >> N;
  int** table = create(M, N);
  input(table, M, N);
  output(table, M, N);
  destroy(table, M, N);
}
