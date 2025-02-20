#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

// function to calculate (a^d) % n efficiently 
long long power(long long a, long long d, long long n) {
  long long res = 1;
  a = a % n;

  while(d > 0){
    if(d%2 == 1)
      res = (res * a) % n;

    a = (a* a) % n;
    d = d / 2;
  }
  return res;
}

// miller rabin primality test
bool millerRabinTest(long long n, int k) {
  // corner cases
  if(n <= 1 || n == 4)
    return false;
  if(n <= 3)
    return true;

  // find r such that n = 2^d * r + 1 for some reason >= 1
  long long d = n - 1;
  while(d % 2 == 0)
    d /= 2;

  // try k times
  for(int i = 0; i < k; i++) {
    long long a = 2 + rand() % (n - 4);
    long long x = power(a, d, n);

    if(x == 1 || x == n - 1)
      continue;

    bool composite = true;
    while(d != n - 1) {
      x = (x * x) % n;
      d *= 2;

      if(x == n - 1) {
        composite = false;
        break;
      }
    }
    if(composite)
      return false;
  }
  return true;
}

int main() {
  srand(time(0));

  long long num;
  int k;

  std::cout << "enter number to test: ";
  std::cint >> num;

  std::cout << "enter number of iterations (k): ";
  std::cin >> k;

  if (millerRabinTest(num,k)) {
    std::cout << num << "is likely prime.\n";
  } else {
    std::cout << num << "is composite.\n";
  }
  return 0;
}
