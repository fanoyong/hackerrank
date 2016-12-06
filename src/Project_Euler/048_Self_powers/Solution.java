
import java.math.BigInteger;
import java.util.Scanner;

public class Solution {

    private static final long MOD = 10000000000L;
    private static final int MAX = 2000000;
    private static BigInteger[] COUNT = new BigInteger[MAX + 1];

    public static void main(String[] args) {
        generateAnswers();
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        System.out.println(COUNT[N]);
        scanner.close();
    }

    private static void generateAnswers() {
        BigInteger mod = BigInteger.ONE;
        mod = mod.multiply(BigInteger.valueOf(MOD));
        for (int i = 1; i <= MAX; i++) {
            if (i % 10 == 0) {
                COUNT[i] = BigInteger.ZERO;
                continue;
            }
            BigInteger mul = BigInteger.ONE;
            mul = mul.multiply(BigInteger.valueOf(i));
            mul = mul.modPow(mul, mod);
            COUNT[i] = mul;
        }
        for (int i = 2; i <= MAX; i++) {
            COUNT[i] = COUNT[i].add(COUNT[i - 1]).mod(mod);
        }
    }
}

