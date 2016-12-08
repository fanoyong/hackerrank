
import java.util.Scanner;
import java.util.TreeSet;

public class Solution {

    private static final boolean DEBUG = true;
    private static final int MAX = 10000000;
    private static final boolean[] SIEVE = new boolean[MAX + 1];
    private static final TreeSet<Integer> ANSWER = new TreeSet<Integer>();

    public static void main(String[] args) {
        generateData();
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        int L = scanner.nextInt();
        generateAnswer(N, K, L);
        scanner.close();
    }

    private static void generateAnswer(final int n, final int k, final int l) {
        // n == 3 -> start: 1000, end:9999,
        int start = (int) Math.pow(10, n - 1);
        int end = (int) (Math.pow(10, n) - 1);
        // k == 2 -> interval = 100 -> 1000 - 1099
        int interval = (int) Math.pow(10, k);
        if (DEBUG) {
            System.out.println("start:" + start + " end:" + end + " interval:" + interval);
        }
        int numOfInterval = (end - start) / interval;
        boolean found = false;
        for (int i = 0; i < numOfInterval; i++) {
            int count = 0;
            for (int j = start + i * interval; j < start + (i + 1) * interval; j++) {
                if (SIEVE[j]) {
                    count++;
                }
                if (count > l+1) {
                    break;
                }
            }
            if (count == l) {
                for (int j = start + i * interval; j < start + (i + 1) * interval; j++) {
                    if (SIEVE[j]) {
                        ANSWER.add(j);
                    }
                }
                found = true;
            }
            if (found) {
                break;
            }
        }
        for (int p : ANSWER) {
            System.out.print(p + " ");
        }
    }

    private static void generateData() {
        for (int i = 0; i <= MAX; i++) {
            SIEVE[i] = true;
        }
        for (int i = 4; i <= MAX; i += 2) {
            SIEVE[i] = false;
        }
        for (int i = 3; i <= Math.sqrt(MAX); i += 2) {
            if (!SIEVE[i]) {
                continue;
            }
            if (isPrime(i)) {
                for (int j = i * 2; j < MAX; j += i) {
                    SIEVE[j] = false;
                }
            }
        }
    }

    private static boolean isPrime(long i) {
        if (i < 2) {
            return false;
        } else if (i == 2 || i == 3) {
            return true;
        } else if ((i & 1) != 1) {
            return false;
        }
        long j = 3;
        while (j <= Math.sqrt(i)) {
            if (i % j == 0) {
                return false;
            }
            j += 2;
        }
        return true;
    }
}

