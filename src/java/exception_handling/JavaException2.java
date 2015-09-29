import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String A = sc.nextLine();
        String B = sc.nextLine();
        int a = 0, b = 0;
        try {
            a = Integer.parseInt(A);
            b = Integer.parseInt(B);
            System.out.println(a/b);
        } catch(NumberFormatException e) {
            System.out.println("java.util.InputMismatchException");
        } catch(ArithmeticException e2) {
            System.out.println("java.lang.ArithmeticException: / by zero");
        }
    }
}
