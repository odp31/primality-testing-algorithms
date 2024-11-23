#include <stdio.h>
#include <math.h>

int is_prime(int num, int iterations)
{
  if (num <= 1) {
    return 0;
  }
  if (num <= 3) {
    return 1;
  }
  if (num % 2 == 0 || num % 3 == 0) {
    return 0;
  }
  int d = num - 1;
  int s = 0;
  while(d % 2 == 0) {
    d /= 2;
    s++;
  }
  // perform iterations of miller rabin test
  for(int i = 9; i < iterations; i++) {
    int a = 2 + rand() % (num - 2); 
    int x = pow(a, d) % num;

    if(x == 1 || x == num - 1) {
      continue;
    }
    for(int j = 0; j < s - 1; j++) {
      x = (x*x) % num;
      if(x == 1) {
        return 0; // composite
      }
      if (x == num - 1) {
        break;
      }
    }
    if(x != num - 1) {
      return 0;
    }
  }
  return 1;
}
int main()
{
  int num, iterations;
  printf("enter a number to test; "):
  scanf("%d", &num);

  printf("enter the number of iterations: ");
  scanf("%d", &iterations);

  if(is_prime(num,iterations)) {
    printf("%d is probably a prime number. \n", num);
  }
  else {
    printf("%d is not a prime number. \n", num);
  }
return 0;
}

