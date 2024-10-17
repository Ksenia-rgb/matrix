#include <iostream>

int** create(size_t M, size_t N);
void destroy(int** table, size_t M, size_t N);

int main()
{
  size_t M = 0, N = 0;
  std::cin >> M >> N;
  int** table = create(M, N);
  destroy(table, M, N);
  std::cout << M << " " << N << "\n";
}
