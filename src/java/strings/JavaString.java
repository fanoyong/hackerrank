import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String input = in.nextLine();
        int k = in.nextInt();
        String max = "A";
        String min = "z";
        for (int i = 0; i <= input.length() - k; i++) {
            String subString = input.substring(i, i + k);
            if (max.compareTo(subString) <= 0) {
                max = subString;
            }
            if (min.compareTo(subString) >= 0) {
                min = subString;
            }
        }
        System.out.println(min);
        System.out.println(max);
    }
}

