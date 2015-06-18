import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        int a, b, n, T, cur, factor;
        Scanner in = new Scanner(System.in);
        T = in.nextInt();
        while (T-- > 0) {
            a = in.nextInt();
            b = in.nextInt();
            n = in.nextInt();
            cur = a;
            factor = 1;
            for (int i = 0; i < n; i++) {
                cur += Math.pow(2, i) * b;
                System.out.print(cur + " ");
            }
            System.out.println("");
        }
    }
}

