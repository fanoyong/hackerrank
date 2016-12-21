import java.math.BigInteger;
import java.util.Scanner;

public class Solution {

    private static final boolean DEBUG = false;

    /**
     * if n is even (e.g. 4), and if answer exists it will be even if n is odd
     * (e.g. 5), and if answer exists it will be odd
     */
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N2 = scanner.nextInt();
        long K = scanner.nextLong();
        int count = 0;
        for (int N = 1; N <= N2; N++) {
            for (int i = 1; i <= N / 2; i++) {
                BigInteger ret = combination(N, i);
                if (DEBUG) {
                    System.out.println("i:" + i + " ret:" + ret);
                }
                if (ret.compareTo(BigInteger.valueOf(K)) > 0) {
                    count += N - 2 * i + 1;
                    break;
                }
            }
        }
        System.out.println(count);
        scanner.close();
    }

    private static BigInteger combination(int n, int r) {
        BigInteger ret = BigInteger.ONE;
        if (r == 0 || r == n) {
            return ret;
        }
        if (r == 1) {
            return BigInteger.valueOf(n);
        }
        // n! / (r! * (n-r)!)
        if (r > (n - r)) {
            for (int i = r + 1; i <= n; i++) {
                ret = ret.multiply(BigInteger.valueOf(i));
            }
            for (int i = 2; i <= n - r; i++) {
                ret = ret.divide(BigInteger.valueOf(i));
            }
        } else {
            for (int i = n - r + 1; i <= n; i++) {
                ret = ret.multiply(BigInteger.valueOf(i));
            }
            for (int i = 2; i <= r; i++) {
                ret = ret.divide(BigInteger.valueOf(i));
            }
        }
        return ret;
    }
}

