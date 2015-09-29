import java.io.*;
import java.util.*;

public class Solution {

    static boolean isAnagram(String A, String B) {
        A = A.toLowerCase();
        B = B.toLowerCase();
        int len_a = A.length();
        int len_b = B.length();
        int dic_a[] = new int['z' - 'a'];
        int dic_b[] = new int['z' - 'a'];
        if (len_a != len_b) {
            return false;
        }
        for (int i = 0; i < len_a; i++) {
            char c = A.charAt(i);
            dic_a[c - 'a']++;
        }
        for (int i = 0; i < len_b; i++) {
            char c = B.charAt(i);
            dic_b[c - 'a']++;
        }

        for (int i = 0; i < 'z' - 'a'; i++) {
            if (dic_a[i] != dic_b[i]) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        String A = sc.next();
        String B = sc.next();
        boolean ret = isAnagram(A,B);
        if(ret)System.out.println("Anagrams");
        else System.out.println("Not Anagrams");
    }
}

