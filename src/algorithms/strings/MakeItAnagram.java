import java.util.Scanner;

public class Solution11 {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        String a = scn.nextLine();
        String b = scn.nextLine();
        scn.close();
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
        int count = 0;
        for (int i = 0; i < 'z' - 'a' + 1; i++) {
            if (aChar[i] != bChar[i]) {
                count += Math.abs(aChar[i] - bChar[i]);
            }
        }
        System.out.println(count);
    }
}

