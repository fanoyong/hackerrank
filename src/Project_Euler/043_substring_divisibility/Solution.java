
import java.util.Scanner;

public class Solution {

    private static final boolean DEBUG = false;

    private static final String ORIGINAL = "0123456789";

    private static final int[] PRIMES = new int[7];
    static {
        PRIMES[0] = 2;
        PRIMES[1] = 3;
        PRIMES[2] = 5;
        PRIMES[3] = 7;
        PRIMES[4] = 11;
        PRIMES[5] = 13;
        PRIMES[6] = 17;
    }

    private static final long[] ANSWER = new long[10];

    public static void main(String[] args) {
        generateAnswers();
        Scanner scanner = new Scanner(System.in);
        int x = scanner.nextInt();
        System.out.println(ANSWER[x]);
        scanner.close();
    }

    private static void generateAnswers() {
        for (int i = 0; i <= 2; i++) {
            ANSWER[i] = 0;
        }
        for (int i = 3; i <= 9; i++) {
            ANSWER[i] = 0;
            char[] subchar = ORIGINAL.substring(0, i + 1).toCharArray();
            String x = String.valueOf(subchar);
            if (isDivisible(x, i)) {
                ANSWER[i] += Long.valueOf(x);
            }
            do {
                int k = i - 1;
                for (; k >= 0; k--) {
                    if (subchar[k] < subchar[k + 1]) {
                        break;
                    }
                }
                if (k < 0) {
                    // End of permutation
                    break;
                }
                int l = i;
                for (; l > k; l--) {
                    if (subchar[l] > subchar[k]) {
                        break;
                    }
                }
                char t = subchar[k];
                subchar[k] = subchar[l];
                subchar[l] = t;
                int i1 = k + 1;
                int i2 = i;
                while (i1 < i2) {
                    t = subchar[i1];
                    subchar[i1] = subchar[i2];
                    subchar[i2] = t;
                    i1++;
                    i2--;
                }
                x = String.valueOf(subchar);
                if (isDivisible(x, i)) {
                    ANSWER[i] += Long.valueOf(x);
                }
            } while (true);
        }
    }

    private static boolean isDivisible(String s, int n) {
        for (int i = 3; i <= n; i++) {
            int prime = PRIMES[i - 3];
            int subInt = Integer.valueOf(s.substring(i - 2, i + 1));
            if (subInt % prime != 0) {
                return false;
            }
        }
        return true;
    }

}

