# simplest method; divide num by all integers from 2 to the square root of number
# if none of these yield a remiander of 0 the number is prime

def is_prime_naive(n):
  if n <= 2:
    return False
  if n <= 3:
    return True
  if n % 2 == 0 or n % 3 == 0:
    return False
  i = 5
  while i * i <= n:
    if n % i == 0 or n % (i + 2) == 0:
      return False
    i += 6
  return True
