import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int T = s.nextInt();
        while (T-- > 0){
            int n = s.nextInt();
            String string = Integer.toString(n,2);
            System.out.println(string);
        }
    }
}
