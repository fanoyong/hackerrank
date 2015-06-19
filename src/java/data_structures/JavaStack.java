import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNextLine()) {
            boolean flag = true;
            String input = sc.nextLine();
            Stack<Character> s = new Stack<Character>();
            for (int i = 0; i < input.length(); i++) {
                char c = input.charAt(i);
                if (c == '}') {
                    // System.out.println("#1 Stack:" + s);
                    if (s.isEmpty() || s.pop() != '{') {
                        // System.out.println("#1 false stack:" + s);
                        flag = false;
                        break;
                    }
                } else if (c == ']') {
                    // System.out.println("#2 Stack:" + s);
                    if (s.isEmpty() || s.pop() != '[') {
                        // System.out.println("#2 false stack:" + s);
                        flag = false;
                        break;
                    }
                } else if (c == ')') {
                    // System.out.println("#3 Stack:" + s);
                    if (s.isEmpty() || s.pop() != '(') {
                        // System.out.println("#3 false stack:" + s);
                        flag = false;
                        break;
                    }
                } else {
                    s.push(c);
                    // System.out.println("push:" + c + "stack: " + s);
                }
            }
            // System.out.println("Decision :" + flag + "isEmpty?" + s.isEmpty());
            if (flag && s.isEmpty()) {
                System.out.println("true");
            } else {
                System.out.println("false");
            }
        }
        sc.close();
    }
}

