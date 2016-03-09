import java.util.Scanner;

public class Solution15 {

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int T = scn.nextInt();
        while (T-- > 0) {
            String s = scn.next();
            char[] cs = s.toCharArray();
            int start = 0, end = s.length() - 1;
            int answer = -1;
            while (start < end) {
                if (cs[start] != cs[end]) {
                    if (start + 1 < end && cs[start + 1] == cs[end] && cs[start + 2] == cs[end - 1]) {
                        answer = start;
                        break;
                    } else if (start + 1 < end && cs[start] == cs[end - 1] && cs[start + 1] == cs[end - 2]) {
                        answer = end;
                        break;
                    } else {
                        // This should not happen based on the assumption
                    }
                }
                start++;
                end--;
            }
            System.out.println(answer);
            // if (isPalinDrome(s)) {
            // System.out.println(-1);
            // } else {
            // System.out.println(getIndex(s));
            // }
        }
        scn.close();
    }

    private static int getIndex(String s) {
        int len = s.length();
        if (isPalinDrome(s.substring(1, len))) {
            return 0;
        } else if (isPalinDrome(s.substring(0, len - 1))) {
            return len - 1;
        }
        for (int i = 1; i < len - 1; i++) {
            StringBuffer sb = new StringBuffer();
            sb.append(s.substring(0, i - 1));
            sb.append(s.substring(i + 1, len));
            if (isPalinDrome(sb.toString())) {
                return i;
            }
        }
        return -1;
    }

    private static boolean isPalinDrome(String s) {
        // System.out.println("isPalinDrom:" + s);
        int start = 0, end = s.length() - 1;
        char[] cs = s.toCharArray();
        while (start < end) {
            if (cs[start] != cs[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

}

