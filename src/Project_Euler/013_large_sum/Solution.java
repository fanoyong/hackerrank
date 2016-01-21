
import java.math.BigInteger;
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        BigInteger sum = BigInteger.valueOf(0);
        while (T-- > 0) {
            String input = sc.next();
            BigInteger bi = new BigInteger(input);
            sum = sum.add(bi);
        }
        sc.close();
        System.out.println(sum.toString().substring(0, 10));
    }
}

