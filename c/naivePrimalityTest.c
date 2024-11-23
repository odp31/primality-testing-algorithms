// checsk divisibility of number n by all integesr from to square root of n 
// if n is divisble by any of these numbers its not prime 

#include <stdio.h>
#include <math.h>

int is_prime(int num)
{
  if (num <= 1)
    return 0;
  if (num <= 3)
    return 1;
  if (num % 2 == 0 || num % 3 == 0)
    return 0;
  for(int i = 5; i * i <= num; i += 6) {
    if(num%i == 0 || num%(i+2) == 0) {
      return 0;
    }
  }
  return 1; 
}

int main()
{
  int num;

  printf("enter a number to test: ");
  scanf("%d", &num);

  if(is_prime(num)) {
    printf("%d is a prime number. \n", num);
  }
  else {
    printf("%d is not a prime nmber. \n", num);
  }
return 0;
}
