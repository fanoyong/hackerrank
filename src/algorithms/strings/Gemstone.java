import java.util.Scanner;

public class Solution10 {

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int T = scn.nextInt();
        boolean isNotGem[][] = new boolean['z' - 'a' + 1][T];
        for (int i = 0; i < 'z' - 'a'; i++) {
            for (int j = 0; j < T; j++) {
                isNotGem[i][j] = false;
            }
        }
        for (int i = 0; i < T; i++) {
            String s = scn.next();
            // System.out.println(s);
            char[] stringc = s.toCharArray();
            for (char c : stringc) {
                isNotGem[c - 'a'][i] = true;
                ;
            }
            // for (int j = 0; j < 'z' - 'a'; j++) {
            // System.out.print(isNotGem[j][i]);
            // }
            // System.out.println();

        }
        scn.close();
        int count = 0;
        for (int i = 0; i < 'z' - 'a'; i++) {
            boolean flag = true;
            for (int j = 0; j < T; j++) {
                if (!isNotGem[i][j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                count++;
            }
        }
        System.out.println(count);
    }
}

