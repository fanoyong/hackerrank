import java.math.BigInteger;
import java.util.Scanner;

public class Solution7 {

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int N = scn.nextInt();
        BigInteger bi = BigInteger.ONE;
        for (int i = 2; i <= N; i++) {
            bi = bi.multiply(BigInteger.valueOf(i));
        }
        System.out.println(bi.toString());
        scn.close();
    }
}

