import java.math.BigInteger;
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        while (T-- > 0) {
            long N = scanner.nextLong();
            // System.out.println(bruteForce(N));
            System.out.println(muchBetter(N));
        }
        scanner.close();
    }

    private static String muchBetter(long n) {
        BigInteger bi = BigInteger.valueOf((n - 1) / 2);
        BigInteger bi1 = bi.pow(3).multiply(BigInteger.valueOf(16));
        BigInteger bi2 = bi.pow(2).multiply(BigInteger.valueOf(30));
        BigInteger bi3 = bi.multiply(BigInteger.valueOf(26)).add(BigInteger.valueOf(3));
        BigInteger answer = bi1.add(bi2).add(bi3).divide(BigInteger.valueOf(3)).mod(BigInteger.valueOf(1000000007L));
        return answer.toString();
    }

    private static long bruteForce(long n) {
        long SUM = 1;
        long end = 1;
        for (long i = 1; i <= n / 2; i++) {
            SUM += (4 * end + 20 * i);
            end = end + 8 * i;
            if (SUM > 1000000007L) {
                SUM %= 1000000007L;
            }
        }
        return SUM;
    }
}

