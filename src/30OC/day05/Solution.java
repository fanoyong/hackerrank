import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int T = s.nextInt();
        while(T-- > 0) {
            int a = s.nextInt();    
            int b = s.nextInt();
            int N = s.nextInt();
            int answer = a;
            for(int i = 0; i<N; i++) {
                answer += Math.pow(2,i) * b;
                System.out.print(answer + " ");
            }
            System.out.println();
        }
        
    }
}
