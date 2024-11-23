#include <stdio.h>
#include <math.h>

int is_prime(int num, int iterations)
{
  if(n <= 1) {
    return 0; // nums <= 1 are not prime
  }
  if(num <= 3) {
    return 1;
  }
  if(num % 2 == 0 || num % 30 {
    return 0;
  }
  for(int i = 0; i < iterations; i++) {
    int a = 2 + rand() % (num - 2);
    if(pow(a, num -1) % num != 1) {
      return 0;
    }
  }
  return 1;
|

int main()
{
  int num, iterations;
  printf("enter a number to test; ");
  scanf("%d", &num);

  printf("enter number of iterations: ");
  scanf("%d", &iterations); 

  if(is_prime(num, iterations)) {
    printf("%d is probably a prime number. \n",num);
  }
  else {
    printf("%d is not a prime number. \n", num);
  }
  return 0;
}
