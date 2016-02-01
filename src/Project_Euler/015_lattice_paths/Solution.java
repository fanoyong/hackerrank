import java.math.BigInteger;
import java.util.Scanner;

public class Solution {
    private static int T, N, M;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        T = in.nextInt();
        while (T-- > 0) {
            N = in.nextInt();
            M = in.nextInt();
            BigInteger bi = new BigInteger("1");
            for (int i = N + 1; i <= N + M; i++) {
                bi = bi.multiply(BigInteger.valueOf(i));
            }
            for (int i = 2; i <= M; i++) {
                bi = bi.divide(BigInteger.valueOf(i));
            }
            int l = 1000000007;
            bi = bi.mod(BigInteger.valueOf(l));
            System.out.println(bi.toString());
        }
    }

}

