import java.math.BigInteger;
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.close();
        if (n < 8 || n > 60) {
            throw new IllegalArgumentException("Invalid percenrage");
        }
        getAnswer(n);
    }

    private static void getAnswer(int n) {
        long primeCount = 0;
        long totalCount = 1;
        long n1 = 1;
        long gap = 2;
        for (int shell = 1;; shell++) {
            // update total count
            totalCount += 4;
            // update primeCount
            for (int i = 0; i < 4; i++) {
                n1 += gap;
                if (isPrime(n1)) {
                    primeCount++;
                }
            }
            gap += 2;
            // System.out.println((double) primeCount / totalCount + " total:" + totalCount);
            double percentage = (primeCount * 100) / totalCount;
            if (percentage < n) {
                System.out.println(2 * shell + 1);
                return;
            }
        }
    }

    private static boolean isPrime(long n) {
        if (n <= 1 || n == 4) {
            return false;
        }
        if (n <= 3) {
            return true;
        }
        for (int i = 3; i <= Math.sqrt(n); i += 2) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    private static boolean isPrime(long n, int k) {
        if (n <= 1 || n == 4) {
            return false;
        }
        if (n <= 3) {
            return true;
        }
        long d = n - 1;
        while (d % 2 == 0) {
            d /= 2;
        }
        for (int i = 0; i < k; i++) {
            if (miillerTest(d, n) == false) {
                return false;
            }
        }
        return true;
    }

    private static boolean miillerTest(long dl, long n) {
        long al = (long) (2 + (Math.random() % (n - 4)));
        BigInteger a = BigInteger.valueOf(al);
        BigInteger nMinusOne = BigInteger.valueOf(n - 1);
        BigInteger x = a.modPow(BigInteger.valueOf(dl), BigInteger.valueOf(n));
        if (x.equals(BigInteger.ONE) || x.equals(nMinusOne)) {
            return true;
        }
        BigInteger d = BigInteger.valueOf(dl);
        while (!d.equals(nMinusOne)) {
            x = x.multiply(x);
            x = x.mod(BigInteger.valueOf(n));
            d = d.multiply(BigInteger.valueOf(2l));
            if (x.equals(BigInteger.ONE)) {
                return false;
            }
            if (x.equals(nMinusOne)) {
                return true;
            }
        }
        return false;
    }

}

