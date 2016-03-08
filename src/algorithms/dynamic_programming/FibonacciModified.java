import java.math.BigInteger;
import java.util.Scanner;

public class Solution9 {

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int A = scn.nextInt();
        int B = scn.nextInt();
        int N = scn.nextInt();
        scn.close();
        BigInteger bi1 = BigInteger.valueOf(A);
        BigInteger bi2 = BigInteger.valueOf(B);
        BigInteger bi3 = BigInteger.ONE;
        for (int i = 3; i <= N; i++) {
            bi3 = bi2.multiply(bi2).add(bi1);
            bi1 = bi2;
            bi2 = bi3;
        }
        System.out.println(bi3);
    }

}

