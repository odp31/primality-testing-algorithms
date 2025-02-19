function fermatPrimalityTest(n, k = 5) {
  if(n<=1) return false;
  if(n<=3) return true;
  if(n%2 === 0) return false;

  for(let i = 0; i < k; i++) {
    let a = Math.floor(Math.random() * (n - 1)) + 2;
    let result = modulatExponentiation(a, n - 1, n);

    if(result !== 1) {
      return false;
    }
  }
  return true;
}

function modularExponentiation(base, exponent, modulus) {
  let result = 1;
  base = base % modulus;

  while(exponent > 0) {
    if(exponent % 2 === 1) [
      result = (result * base) % modulus;
  }
  base = (base * base) % modulus;
  exponent = Math.floor(exponent / 2);
}
return result;
}


// example usage
let numToCheck = 17;
let isPrime = fermatPrimalityTest(numToCheck);

if(isPrime) {
  console.log(numToCheck + "is likely prime");
} else {
  console.log(numToCheck + "is composite");
}

numToCheck = 15;
isPrime = fermatPrimalityTest(numToCheck);

if(isPrime) {
  console.log(numToCheck + "is likely prime");
} else {
  console.log(numToCheck + "is composite");
}

numToCheck = 561;
isPrime = fermatPrimalityTest(numToCheck, 10);

if(isPrime) {
  console.log(numToCheck + "is likely prime");
} else {
  console.log(numToCheck + "is composite");
}

// test with large prime
numToCheck = 7919;
isPrime = fermatPrimalityTest(numToCheck);
if(isPrime) {
  console.log(numToCheck + "is likely prime");
} else {
  console.log(numToCheck + "is composite");
}
