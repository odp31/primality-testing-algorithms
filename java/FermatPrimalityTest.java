import java.math.BitInteger;
import java.util.Random;

public class FermatPrimalityTest
  {
    public static boolean isProbablyPrime(BigInteger n, int iterations)
    {
      if(n.compareTo(BigInteger.TWO) < 0)
      {
        return false;
      }
      else if(n.compareTo(BigInteger.TWO) == 0)
      {
        return true;
      }
      else if(n.mod(BigInteger.TWO).equals(BigInteger.ZERO))
      {
        return false;
      }
      Random rand = new Random();
      for(int i = 0; i < iterations; i++)
        {
          BigInteger a = BigInteger.probableprime(n.bigLength() - 1, rand);
          if(!a.modPow(n.subtract(BigInteger.ONE), n).equals(BigInteger.ONE))
          {
            return false;
          }
        }
      return true;
    }

    public static void main(String[] args)
    {
        BigInteger number = new BigInteger("123456789101112131415161718192021");
        int iterations = 10;

        if(isProbablyPrime(number, iterations))
        {
          System.out.println(number + " is probably prime.");
        }
        else{
          System.out.println(number + "is composite");
        }
    }
  }
          
