import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        sc.nextLine();
        HashSet<String> hs = new HashSet<String>();
        while (T-- > 0) {
            hs.add(sc.nextLine());
            System.out.println(hs.size());
        }
    }
}

