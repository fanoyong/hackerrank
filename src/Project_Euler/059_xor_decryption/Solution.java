import java.util.Scanner;

public class Solution {

    private static boolean[] FIRST = new boolean['z' - 'a' + 1];
    private static boolean[] SECOND = new boolean['z' - 'a' + 1];
    private static boolean[] THIRD = new boolean['z' - 'a' + 1];

    public static void main(String[] args) {
        for (int i = 0; i < 'z' - 'a' + 1; i++) {
            FIRST[i] = true;
            SECOND[i] = true;
            THIRD[i] = true;
        }
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        for (int i = 0; i < N / 3; i++) {
            int i1 = scanner.nextInt();
            for (char c = 'a'; c <= 'z'; c++) {
                if (!FIRST[c - 'a']) {
                    continue;
                }
                if (isValid(c, i1)) {
                    FIRST[c - 'a'] = false;
                }
            }
            int i2 = scanner.nextInt();
            for (char c = 'a'; c <= 'z'; c++) {
                if (!SECOND[c - 'a']) {
                    continue;
                }
                if (isValid(c, i2)) {
                    SECOND[c - 'a'] = false;
                }
            }
            int i3 = scanner.nextInt();
            for (char c = 'a'; c <= 'z'; c++) {
                if (!THIRD[c - 'a']) {
                    continue;
                }
                if (isValid(c, i3)) {
                    THIRD[c - 'a'] = false;
                }
            }
        }
        scanner.close();
        for (int i = 0; i < FIRST.length; i++) {
            System.out.println(FIRST[i]);
        }
        StringBuilder sb = new StringBuilder();
        for (char c = 'a'; c <= 'z'; c++) {
            if (FIRST[c - 'a']) {
                sb.append(c);
            }
        }
        for (char c = 'a'; c <= 'z'; c++) {
            if (SECOND[c - 'a']) {
                sb.append(c);
            }
        }
        for (char c = 'a'; c <= 'z'; c++) {
            if (THIRD[c - 'a']) {
                sb.append(c);
            }
        }
        System.out.println(sb.toString());
    }

    private static boolean isValid(char c, int i) {
        int xor = (c ^ i);
        if ((xor >= 'a' && xor <= 'z') || (xor >= 'A' && xor <= 'Z') || (xor >= '0' && xor <= '9')
                || (xor == '(' || xor == ')') || (xor == ';' || xor == ':') || (xor == ',' || xor == '.')
                || (xor == '\'' || xor == '?') || (xor == '-' || xor == '!')) {
            return true;
        }
        return false;
    }
}
