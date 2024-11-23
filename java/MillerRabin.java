// more robust probabilistic primality test than fermats
// used in cryptographic applications due to its efficiency and accuracy 

import java.math.BigInteger;
import java.util.Random; 

public class MillerRabin
  {
    public static boolean isProbablyPrime(BigInteger n, int iterations)
    {
      if(n.compareTo(BigInteger.TWO) < 0)
      {
        return false;
      }
      else if(n.compareTo(BigInteger.TWO) == 0 || n.compareTo(BigInteger.THREE) == 0)
      {
        return true;
      }
      else if(n.mod(BigInteger.TWO).equals(BigInteger.ZERO) || n.mod(BigInteger.THREE).equals(BigInteger.ZERO))
      {
        return false;
      }
      BigInteger d = n.subtract(BigInteger.ONE);
      int s = 0;
      while(d.mod(BigInteger.TWO).equals(BigInteger.ZERO))
        {
          d = d.divide(BigInteger.TWO);
          s++;
        }
      Random rand = new Random();
      for(int i = 0; i < iterations; i++)
        {
          BigInteger a = BigInteger.probablePrime(n.bitLength() - 1, rand);
          BigInteger x = a.modPow(d, n);

          if(x.equals(BigInteger.ONE) || x.equals(n.subtract(BigInteger.ONE)))
          {
            continue;
          }
          for(int j = 0; j < s; j++)
            {
              x = x.pow(2).mod(n);
              if(x.equals(BigInteger.ONE))
              {
                return false;
              }
              else if(x.equals(n.subtract(BigInteger.ONE)))
              {
                break;
              }
            }
          if(!x.equals(n.subtract(BigInteger.ONE)))
          {
            return false;
          }
        }
      return true;
    }
    public static void main(String[] args)
    {
      BigInteger number = new BigInteger("123456789101112131415161718192021");
      int iterations = 20; 
      if(isProbablyPrime(number, iterations))
      {
        System.out.println(number + "is probably prime.");
      }
      else
      {
        System.out.println(number + "is composite");
      }
    }
  }


      
