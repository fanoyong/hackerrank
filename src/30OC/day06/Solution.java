import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        for(int i = 1; i<=t; i++){
            for(int j=t-i; j>=1; j--) {
                System.out.print(" ");
            }
            for(int j=0;j<i;j++){
                System.out.print("#");
            }
            System.out.println();
        }
    }
}
