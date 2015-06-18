import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        int T;
        Scanner in = new Scanner(System.in);
        String input = in.nextLine();
        Boolean[] fit = new Boolean[4];
        T = Integer.valueOf(input);
        while (T-- > 0) {
            input = in.nextLine();
            fit[0] = false;
            fit[1] = false;
            fit[2] = false;
            fit[3] = false;
            try {
                Byte.valueOf(input);
                fit[0] = true;
                fit[1] = true;
                fit[2] = true;
                fit[3] = true;
            } catch (NumberFormatException nfe) {
                // Do nothing
            }
            try {
                Short.valueOf(input);
                fit[1] = true;
                fit[2] = true;
                fit[3] = true;
            } catch (NumberFormatException nfe) {
                // Do nothing
            }
            try {
                Integer.valueOf(input);
                fit[2] = true;
                fit[3] = true;
            } catch (NumberFormatException nfe) {
                // Do nothing
            }
            try {
                Long.valueOf(input);
                fit[3] = true;
            } catch (NumberFormatException nfe) {
                // Do nothing
            }
            print(input, fit);
        }
    }

    private static void print(String input, Boolean[] fit) {
        if (!fit[0] && !fit[1] && !fit[2] && !fit[3]) {
            System.out.println(input + " can't be fitted anywhere.");
            return;
        }
        System.out.println(input + " can be fitted in:");
        if (fit[0]) {
            System.out.println("* byte");
            System.out.println("* short");
            System.out.println("* int");
            System.out.println("* long");
        } else if (fit[1]) {
            System.out.println("* short");
            System.out.println("* int");
            System.out.println("* long");
        } else if (fit[2]) {
            System.out.println("* int");
            System.out.println("* long");
        } else if (fit[3]) {
            System.out.println("* long");
        }
    }
}

