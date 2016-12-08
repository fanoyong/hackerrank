
import java.util.Scanner;

public class Solution {

    private static final boolean DEBUG = true;
    private static final int MAX = 10000000;
    private static final boolean[] SIEVE = new boolean[MAX + 1];

    public static void main(String[] args) {
        generateData();
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        int L = scanner.nextInt();
        generateAnswer(N, K, L);
        scanner.close();
    }

    private static void generateAnswer(int n, int k, int l) {
        int start, end;

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

