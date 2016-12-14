
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
        if (n <= 1) {
            return false;
        } else if (n <= 3) {
            return true;
        } else if ((n & 1) != 1) {
            return false;
        }
        long d = n - 1;
        while (d % 2 == 0) {
            d /= 2;
        }
        while (k-- > 0) {
            if (!millerTest(n, d)) {
                return false;
            }
        }
        return true;
    }

    private static boolean millerTest(long n, long d) {
        long a = (long) Math.random() * (n - 4) + 2;
        long x = (long) (Math.pow(a, d) % n);
        if (x == 1 || x == (n - 1)) {
            return true;
        }
        while (d != n - 1) {
            x = (x * x) % n;
            d *= 2;
            if (x == 1) {
                return false;
            }
            if (x == n - 1) {
                return true;
            }
        }
        return false;
    }
}

