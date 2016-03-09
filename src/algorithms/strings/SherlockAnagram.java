import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Solution14 {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int T = scn.nextInt();
        while (T-- > 0) {
            final String s = scn.next();
            Set<String> sets = new HashSet<String>();
            for (int len = 1; len <= s.length() - 1; len++) {
                for (int i = 0; i < s.length() - len; i++) {
                    for (int j = i + 1; j < s.length() - len + 1; j++) {
                        char[] a = s.substring(i, i + len).toCharArray();
                        char[] b = s.substring(j, j + len).toCharArray();
                        java.util.Arrays.sort(a);
                        java.util.Arrays.sort(b);
                        String ax = Arrays.toString(a);
                        String bx = Arrays.toString(b);
                        // System.out.println("a:" + ax + " b: " + bx);
                        if (ax.equals(bx)) {
                            sets.add(a.toString());
                        }
                    }
                }
            }
            System.out.println(sets.size());
        }
        scn.close();
    }
}

