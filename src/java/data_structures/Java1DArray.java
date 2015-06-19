import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    static int[] array = new int[101];
    static boolean[] visit = new boolean[101];
    static int m;
    static int n;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- > 0) {
            n = sc.nextInt();
            m = sc.nextInt();
            // System.out.println("#" + (5000 - T) + "n:" + n + "m" + m);a
            for (int i = 0; i < n; i++) {
                array[i] = sc.nextInt();
                visit[i] = false;
            }
            if (m == 1) {
                int i;
                for (i = 0; i < n; i++) {
                    if (array[i] != 0) {
                        System.out.println("NO");
                        break;
                    }
                }
                if (i == n) {
                    System.out.println("YES");
                }
            } else {
                if (traverse(0)) {
                    System.out.println("YES");
                } else {
                    System.out.println("NO");
                }
            }
        }
        sc.close();
    }

    private static boolean traverse(int i) {
        if (i >= n) {
            return true;
        }
        if (i < 0) {
            return false;
        }
        if (visit[i]) {
            return false;
        }
        visit[i] = true;
        if (array[i] != 0) {
            return false;
        }
        if (i + m >= n || i + 1 >= n) {
            return true;
        }
        return traverse(i + m) || traverse(i - 1) || traverse(i + 1);
    }
}

