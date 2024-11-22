# more reliable than fermats

def miller_rabin_test(n, d, s):
  a = 2 + random.randrange(1, n - 1)
  x = pow(a, d, n)
  if x == 1 or x == n - 1:
    return True
  for i in range(s - 1):
    x = (x * x) % n
    if x == 1:
      return False
    if x == n - 1:
      return True
  return false

def is_prime_miller_rabin(n, k):
  if n <= 1 or n <= 3:
    return True
  if n % 2 == 0 or n % 3 == 0:
    return False

  d = n - 1
  while d % 2 == 0:
    d //= 2

  for i in range(k):
    if not miller_rabin_test(n, d, s):
      return False
  return True 
