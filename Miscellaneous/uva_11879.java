import java.math.BigInteger;
import java.util.*;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        BigInteger val = new BigInteger("0");

        while(true)
        {
            BigInteger n = sc.nextBigInteger();
            if(n.compareTo(val)==0)
                break;
            
            BigInteger r = n.mod(BigInteger.valueOf(10));
            n = n.divide(BigInteger.valueOf(10));
            BigInteger result =n.subtract(r.multiply(BigInteger.valueOf(5))).abs();
            BigInteger finalRes = result.mod(BigInteger.valueOf(17));
            if(finalRes.compareTo(val) == 0)
                System.out.println("1");
            else
                System.out.println("0");


        }

    }
}




