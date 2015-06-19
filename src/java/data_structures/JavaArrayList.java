import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<ArrayList> ar = new ArrayList<ArrayList>();
        for (int i = 0; i < n; i++) {
            int d = sc.nextInt();
            ArrayList<Integer> list = new ArrayList<Integer>();
            for (int j = 0; j < d; j++) {
                list.add(sc.nextInt());
            }
            ar.add(list);
        }
        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            int a = sc.nextInt() - 1;
            int b = sc.nextInt() - 1;
            if (ar.size() <= a || ar.get(a).size() <= b) {
                System.out.println("ERROR!");
            } else {
                System.out.println(ar.get(a).get(b));
            }
        }
    }
}

