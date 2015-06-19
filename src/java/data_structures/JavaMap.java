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
        HashMap<String, String> phonebook = new HashMap<String, String>();
        for (int i = 0; i < T; i++) {
            String name = sc.nextLine();
            String num = sc.nextLine();
            phonebook.put(name, num);
        }
        for (int i = 0; i < T; i++) {
            String query = sc.nextLine();
            String result = phonebook.get(query);
            if (result == null) {
                System.out.println("Not found");
            } else {
                System.out.println(query + "=" + result);
            }
        }
        sc.close();
    }
}

