
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class Solution {
    private static final int MAX_P = 5000000;
    private static final List<Integer> TRIPLET_LIST = new ArrayList<Integer>();
    private static final Set<Integer> TRIPLET_SET = new HashSet<Integer>();
    private static int[] SIEVE = new int[MAX_P + 1];
    private static boolean[] ISPRIME = new boolean[MAX_P + 1];

    public static void main(String[] args) {
        generateTriplets();
        getMaxPerimeter();
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while (t-- > 0) {
            int n = scanner.nextInt();
            System.out.println(SIEVE[n]);
        }
        scanner.close();
    }

    private static void getMaxPerimeter() {
        TRIPLET_LIST.addAll(TRIPLET_SET);
        Collections.sort(TRIPLET_LIST);
        for (int i = 0; i <= MAX_P; i++) {
            SIEVE[i] = 0;
            ISPRIME[i] = true;
        }
        for (int p : TRIPLET_LIST) {
            for (int i = p * 2; i <= MAX_P; i += p) {
                ISPRIME[i] = false;
            }
        }
        for (int p : TRIPLET_LIST) {
            if (!ISPRIME[p]) {
                continue;
            }
            for (int i = p; i <= MAX_P; i += p) {
                SIEVE[i]++;
            }
        }
        int cur = 0;
        int curi = 0;
        for (int i = 0; i <= MAX_P; i++) {
            if (SIEVE[i] > cur) {
                cur = SIEVE[i];
                curi = i;
            }
            SIEVE[i] = curi;
        }
    }

    private static void generateTriplets() {
        for (int m = 3; m < 3000; m += 2) {
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
                if (TRIPLET_SET.contains(p)) {
                    continue;
                }
                TRIPLET_SET.add(p);
            }
        }
    }

}

