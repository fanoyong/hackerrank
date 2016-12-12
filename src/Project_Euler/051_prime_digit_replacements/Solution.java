
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
        int gapBasis = 0;
        for (int i = 0; i < k; i++) {
            gapBasis += (int) Math.pow(10, i);
        }
        int firstPrime = start;
        while (firstPrime < end) {
            while (!SIEVE[firstPrime]) {
                firstPrime++;
            }
            int gap = gapBasis;
            int gapEnd = (int) Math.pow(10, k);
            int gapStart = (firstPrime / gapEnd) * gapEnd;
            int index = firstPrime;
            boolean flag = false;
            while (gapStart + gap < end) {
                gapStart = (firstPrime / gapEnd) * gapEnd;
                int count = 0;
                boolean found = false;
                for (int i = firstPrime; i < gapStart + gapEnd - 1; i += gap) {
                    if (SIEVE[i]) {
                        count++;
                    }
                    if (count == l) {
                        found = true;
                        break;
                    }
                }
                if (found) {
                    count = 0;
                    flag = true;
                    for (int i = firstPrime; i < gapStart + gapEnd - 1; i += gap) {
                        if (SIEVE[i]) {
                            ANSWER.add(i);
                            count++;
                        }
                        if (count == l) {
                            break;
                        }
                    }
                    break;
                }

                gap *= 10;
                gapEnd *= 10;
            }
            if (flag) {
                break;
            }
            firstPrime++;
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

