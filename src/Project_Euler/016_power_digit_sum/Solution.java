import java.math.BigInteger;
import java.util.Scanner;

public class Solution {
    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);
        char[] ara = new char[10000];
        int T = sc.nextInt();
        while (T-- > 0) {
            long ans = 0;
            int N = sc.nextInt();
            BigInteger num = new BigInteger("2");
            ara = num.pow(N).toString().toCharArray();
            for (int i = 0; i < ara.length; i++) {
                ans = ans + ara[i] - '0';
            }
            System.out.println(ans);
        }

    }

}

