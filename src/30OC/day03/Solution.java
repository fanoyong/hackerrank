import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        String ans;
        if ((n%2==0 && n > 20) || n==2 || n==4) {
            System.out.println("Not Weird");
        } else {
            System.out.println("Weird");
        }
    }
}
