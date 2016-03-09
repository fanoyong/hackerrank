import java.util.Scanner;

public class Solution12 {

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int T = scn.nextInt();
        while (T-- > 0) {
            String s = scn.next();
            if ((s.length() & 1) == 1) {
                System.out.println(-1);
                continue;
            }
            String a = s.substring(0, s.length() / 2);
            String b = s.substring(s.length() / 2, s.length());
            int aChar[] = new int['z' - 'a' + 1];
            int bChar[] = new int['z' - 'a' + 1];
            for (int i = 0; i < 'z' - 'a' + 1; i++) {
                aChar[i] = 0;
                bChar[i] = 0;
            }
            for (char c : a.toCharArray()) {
                aChar[c - 'a']++;
            }
            for (char c : b.toCharArray()) {
                bChar[c - 'a']++;
            }
            // System.out.println("s:" + s + " a:" + a.toString() + " b:" + b.toString());
            int count = 0;
            for (int i = 0; i < 'z' - 'a' + 1; i++) {
                int diff = aChar[i] - bChar[i];
                if (diff > 0) {
                    // System.out.println("a:" + aChar[i] + " b:" + bChar[i] + " diff:" + diff);
                    count += diff;
                }
            }
            System.out.println(count);
        }
        scn.close();
    }

}

