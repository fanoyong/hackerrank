import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- > 0) {
            long N = sc.nextLong();
            BigInteger bi = BigInteger.ONE;
            for (long i = 1; i <= N; i++) {
                bi = bi.multiply(BigInteger.valueOf(i));
            }
            char[] digits = bi.toString().toCharArray();
            long count = 0;
            for (int i = 0; i < digits.length; i++) {
                char c = digits[i];
                count += Integer.parseInt(String.valueOf(c));
            }
            System.out.println(count);
        }
    }
}

