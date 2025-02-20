#include <iostream>
#include <cstdlib>
#include <ctime>

// function to calculate (a^d) % n efficiently

long long power(long long a, long long d, long long n) {
  long long res = 1;
  a = a % n;
  while(d > 0) {
    if(d%2 == 1)
      res = (res * a) % n;
    a = (a * a) % n;
    d = d / 2;
  }
  return res;
}

// fermat primality test
bool fermatPrimalityTest(long long n, int k) {
  // corner cases
  if(n <= 1 || n == 4)
    return false;
  if(n <= 3)
    return true;

  // try k times
  for(int i = 0; i < k; i++) {
    long long a = 2 + rand() % (n - 4);
    if(power(a, n - 1, n) != 1)
      return false;
  }
  return true;
}

int main() {
  srand(time(0));

  long long num;
  int k;

  std::cout << "enter a number to test: ";
  std::cin >> num;

  std::cout << "enter number of iterations (k): ";
  std::cin >> k;

  if(fermatPrimalityTest(num, k)) {
    std::cout << num << " is likely prime.\n";
  } else {
    std::cout << num << "is composite.\n";
  }
  return 0;
}
