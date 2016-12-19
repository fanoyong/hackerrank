
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.TreeMap;

public class Solution {

    private static long[] ARRAY;
    private static int COUNT;
    private static TreeMap<Long, Integer> ANSWERS = new TreeMap<Long, Integer>();
    private static ArrayList<Long> PRIMES = new ArrayList<Long>();

    public static void main(String[] args) {
        generateData();
        generateAnswer();
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        while (T-- > 0) {
            long N = scanner.nextLong();
            int length = Integer.MIN_VALUE;
            long answer = 0;
            for (long sum : ANSWERS.keySet()) {
                if (sum > N) {
                    continue;
                }
                if (length < ANSWERS.get(sum)) {
                    length = ANSWERS.get(sum);
                    answer = sum;
                }
            }
            System.out.println(answer + " " + length);
        }
        scanner.close();
    }

    private static void generateAnswer() {
        for (int i = 0; i < COUNT; i++) {
            for (int j = i + 1; j < COUNT; j++) {
                long sum = 0;
                for (int k = i; k <= j; k++) {
                    sum += ARRAY[k];
                }
                if (isPrime(sum, 4)) {
                    if (!ANSWERS.containsKey(sum) || ANSWERS.get(sum) < (j - i + 1)) {
                        ANSWERS.put(sum, (j - i + 1));
                    }
                }
            }
        }
    }

    private static void generateData() {
        COUNT = 0;
        PRIMES.add(2L);
        long n = 3;
        while (COUNT < 1400) {
            if (isPrime(n, 4)) {
                COUNT++;
                PRIMES.add(n);
            }
            n += 2;
        }
        ARRAY = new long[PRIMES.size()];
        COUNT = 0;
        for (Long l : PRIMES) {
            ARRAY[COUNT++] = l;
        }
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

