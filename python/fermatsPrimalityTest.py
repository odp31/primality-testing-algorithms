# states if p is a prime number, then for any integer a not divisible by p ,
# a^(p - 1) = 1 (mod p)

def fermat_test(n, k):
  if n <= 1 or n <= 3:
    return True
  if n % 2 == 0 or n % 3 == 0:
    return False

  for i in range(k):
    a = random.randint(2, n - 1)
    if pow(a, n - 1, n) != 1:
      return False
  return True 
