import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long N = scanner.nextLong();
        int K = scanner.nextInt();
        scanner.close();
        long cur = 0;
        long cur2;
        while (cur <= N) {
            boolean flag = true;
            for (int i = 2; i <= K; i++) {
                cur2 = cur * i;
                if (!isSame(cur, cur2)) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                for (int i = 0; i < K; i++) {
                    System.out.print(cur * (i + 1) + " ");
                }
                System.out.println();
            }
            cur++;
        }
    }

    private static boolean isSame(long cur, long cur2) {
        String s1 = String.valueOf(cur);
        String s2 = String.valueOf(cur2);
        if (s1.length() != s2.length()) {
            return false;
        } else if (s1.endsWith("0") || s2.endsWith("0")) {
            return false;
        }
        char[] cs1 = s1.toCharArray();
        java.util.Arrays.sort(cs1);
        char[] cs2 = s2.toCharArray();
        java.util.Arrays.sort(cs2);
        return String.valueOf(cs1).equals(String.valueOf(cs2));
    }
}

