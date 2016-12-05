
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Solution {

    private static final ArrayList<Long> ANSWERS = new ArrayList<Long>();
    private static final boolean DEBUG = false;

    public static void main(String[] args) {
        generateData();
        Collections.sort(ANSWERS);
        if (ANSWERS.isEmpty()) {
            return;
        }
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while (t-- > 0) {
            long n = scanner.nextLong();
            if (ANSWERS.get(0) > n) {
                System.out.println(-1);
            } else {
                int i = 0;
                for (; i < ANSWERS.size(); i++) {
                    if (ANSWERS.get(i) > n) {
                        break;
                    }
                }
                i--;
                System.out.println(ANSWERS.get(i));
            }
        }
        scanner.close();

    }

    private static void generateData() {
        final String SOURCE = "123456789";
        for (int start = 2; start <= 9; start++) {
            char[] subchar = SOURCE.substring(0, start).toCharArray();
            // 5 3 4 2 1
            // 5 4 1 2 3
            // 5 4 1 3 2
            long newnum = Integer.valueOf(String.valueOf(subchar));
            if (isPrime(newnum) && isPandigital(newnum)) {
                if (DEBUG) {
                    System.out.println("ADDED:" + newnum);
                }
                ANSWERS.add(newnum);
            }
            do {
                int k = start - 2;
                for (; k >= 0; k--) {
                    if (subchar[k] < subchar[k + 1]) {
                        break;
                    }
                }
                if (k < 0) {
                    // End of permutation
                    break;
                }
                int l = start - 1;
                for (; l > k; l--) {
                    if (subchar[l] > subchar[k]) {
                        break;
                    }
                }
                char t = subchar[k];
                subchar[k] = subchar[l];
                subchar[l] = t;
                int i1 = k + 1;
                int i2 = start - 1;
                while (i1 < i2) {
                    t = subchar[i1];
                    subchar[i1] = subchar[i2];
                    subchar[i2] = t;
                    i1++;
                    i2--;
                }
                newnum = Integer.valueOf(String.valueOf(subchar));
                if (isPrime(newnum) && isPandigital(newnum)) {
                    if (DEBUG) {
                        System.out.println("ADDED:" + newnum);
                    }
                    ANSWERS.add(newnum);
                }
            } while (true);
        }
    }

    private static boolean isPrime(long n) {
        if (n < 2) {
            return false;
        } else if (n == 2 || n == 3) {
            return true;
        } else if ((n & 1) != 1) {
            return false;
        }
        for (int i = 3; i <= Math.sqrt(n); i += 2) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    private static boolean isPandigital(long n) {
        boolean[] mark = new boolean[10];
        for (int i = 0; i < 10; i++) {
            mark[i] = false;
        }
        while (n > 0) {
            int digit = (int) (n % 10);
            if (mark[digit]) {
                return false;
            } else {
                mark[digit] = true;
            }
            n /= 10;
        }
        int indexhigh = 1;
        for (int i = 9; i >= 1; i--) {
            if (mark[i]) {
                indexhigh = i;
                break;
            }
        }
        for (int i = 1; i <= indexhigh; i++) {
            if (!mark[i]) {
                return false;
            }
        }
        return true;
    }
}

