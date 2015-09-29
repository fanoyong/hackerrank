import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] data = new int[N];
        for (int i = 0; i<N; i++) {
            data[i] = sc.nextInt();
        }
        int count = 0;
        for (int i = 0; i<N; i++) {
            for (int j = i; j<N; j++) {
                if(sum(data, i, j) < 0) {
                    count++;
                }
            }
        }
        System.out.println(count);
    }
    
    private static int sum(int[] data, int a, int b) {
        int sum = 0;
        for(int i = a; i<=b; i++) {
            sum += data[i];
        }
        return sum;
    }
}
