import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger num1 = new BigInteger(sc.nextLine());
        BigInteger num2 = new BigInteger(sc.nextLine());
        System.out.println(num1.add(num2));
        System.out.println(num1.multiply(num2));
    }
}

