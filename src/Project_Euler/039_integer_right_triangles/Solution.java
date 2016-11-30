
import java.util.HashMap;
import java.util.Scanner;

public class Solution {
    private static final int MAX_P = 5000000;
    private static boolean[] PRIME = new boolean[MAX_P + 1];
    private static int[] SIEVE = new int[MAX_P + 1];
    private static int[] SIEVEI = new int[MAX_P + 1];
    private static HashMap<Integer, Triple> TRIPLESET = new HashMap<Integer, Triple>();

    private static class Triple implements Comparable<Triple> {
        private int mA;
        private int mB;
        private int mC;
        private int mP;

        public Triple(int a, int b, int c) {
            mA = a;
            mB = b;
            mC = c;
            mP = a + b + c;
        }

        @Override
        public int compareTo(Triple o) {
            return Integer.compare(mP, o.mP);
        }

        @Override
        public String toString() {
            return mP + " " + mA + " " + mB + " " + mC;
        }
    }

    public static void main(String[] args) {
        generateTriplets();
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while (t-- > 0) {
            int n = scanner.nextInt();
            System.out.println(SIEVEI[n]);
        }
        scanner.close();
    }

    private static void generateTriplets() {

        for (int i = 0; i <= MAX_P; i++) {
            SIEVE[i] = 0;
            SIEVEI[i] = 0;
            PRIME[i] = false;
        }

        for (int m = 3; m < 2300; m += 2) {
            int msq = m * m;
            for (int n = 1; n <= m; n += 2) {
                if (n != 1 && m % n == 0) {
                    continue;
                }
                int nsq = n * n;
                int a = m * n;
                int b = (msq - nsq) / 2;
                int c = (msq + nsq) / 2;
                int p = a + b + c;
                if (p > MAX_P) {
                    continue;
                }
                Triple triple = new Triple(a, b, c);
                if (!PRIME[p]) {
                    for (int i = p; i <= MAX_P; i += p) {
                        PRIME[i] = true;
                        SIEVE[i]++;
                    }
                    TRIPLESET.put(p, triple);
                }
            }
        }

        for (int p : TRIPLESET.keySet()) {

        }
        int cur = 0;
        int curi = 0;
        for (int i = 0; i <= MAX_P; i++) {
            if (SIEVE[i] > cur) {
                cur = SIEVE[i];
                curi = i;
            }
            SIEVEI[i] = curi;
        }
    }
}

