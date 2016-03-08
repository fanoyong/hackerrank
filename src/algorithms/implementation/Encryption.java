import java.util.Scanner;

public class Solution8 {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        String original = scn.nextLine();
        scn.close();
        int length = original.length();
        // int row = (int) Math.floor(Math.sqrt(length));
        int col = (int) Math.ceil(Math.sqrt(length));
        for (int i = 0; i < col; i++) {
            int index = i;
            while (index < length) {
                System.out.print(original.charAt(index));
                index += col;
            }
            System.out.print(" ");
        }
    }
}

