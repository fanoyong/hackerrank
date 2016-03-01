import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

public class Solution {

    private static int DATA[] = new int[5002];
    private static int DATA2[] = new int[5002];

    private static void bruteForce() {
        BigInteger bi1 = BigInteger.valueOf(1);
        BigInteger bi2 = BigInteger.valueOf(1);
        BigInteger bi3;
        int term = 3;
        int digit = 1;
        int cur;
        DATA[1] = 1;
        while (digit <= 5000) {
            bi3 = bi1.add(bi2);
            cur = bi3.toString().length();
            if (cur > digit) {
                System.out.println(term);
                ;
                digit = cur;
                DATA[digit] = term;
            }
            bi1 = bi2;
            bi2 = bi3;
            term++;
        }

        int T, N;
        Scanner scanner = new Scanner(System.in);
        T = scanner.nextInt();
        while (T-- > 0) {
            N = scanner.nextInt();
            System.out.println(DATA[N]);
        }
        scanner.close();
    }

    public static void main(String[] args) {
        // bruteForce();
        approximate();
    }

    private static void approximate() {
        int T, N;
        final double OMEGA = (1 + Math.sqrt(5)) / 2;
        // F_n <= Omega^n / sqrt(5) + 0.5 < 10^digit
        // log (F_N) <= n * log(Omega) - log(sqrt(5)) < digit * log 10
        // For digit 1 ... 5000, find n argmax (n * log(Omega) - log(sqrt(5)))

        int term = 1;
        double fn;
        for (int i = 1; i <= 5000; i++) {
            double l = (i * Math.log(10));
            // System.out.println("L=" + l);
            do {
                fn = term * Math.log(OMEGA) - Math.log(Math.sqrt(5));
                // System.out.println("F_" + term + "= " + fn);
                term++;
            } while (l > fn);
            DATA2[i] = term - 1;
        }
        Scanner scanner = new Scanner(System.in);
        T = scanner.nextInt();
        while (T-- > 0) {
            N = scanner.nextInt();
            System.out.println(DATA2[N - 1]);
        }
        scanner.close();
    }
}

