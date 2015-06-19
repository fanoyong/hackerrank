import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    private static int ARRAY[][] = new int[6][6];
    private static int MAX, MAXI, MAXJ;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        MAX = Integer.MIN_VALUE;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                ARRAY[i][j] = sc.nextInt();
            }
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int temp = sum(i, j);
                if (temp > MAX) {
                    MAX = temp;
                    MAXI = i;
                    MAXJ = j;
                }
            }
        }
        System.out.println(MAX);
        // print(MAXI, MAXJ);
    }

    private static int sum(int i, int j) {
        return ARRAY[i][j] + ARRAY[i][j + 1] + ARRAY[i][j + 2] +
                ARRAY[i + 1][j + 1] +
                ARRAY[i + 2][j] + ARRAY[i + 2][j + 1] + ARRAY[i + 2][j + 2];
    }

    private static void print(int i, int j) {
        System.out.println(ARRAY[i][j] + " " + ARRAY[i][j + 1] + " " + ARRAY[i][j + 2]);
        System.out.println("  " + ARRAY[i + 1][j + 1]);
        System.out.println(ARRAY[i + 2][j] + " " + ARRAY[i + 2][j + 1] + " " + ARRAY[i + 2][j + 2]);
    }
}

