
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class Solution {

    final private static HashMap<Integer, BigInteger> FACT = new HashMap<Integer, BigInteger>();

    static {
        FACT.put(0, BigInteger.ONE);
        FACT.put(1, BigInteger.ONE);
        FACT.put(2, FACT.get(1).multiply(BigInteger.valueOf(2)));
        FACT.put(3, FACT.get(2).multiply(BigInteger.valueOf(3)));
        FACT.put(4, FACT.get(3).multiply(BigInteger.valueOf(4)));
        FACT.put(5, FACT.get(4).multiply(BigInteger.valueOf(5)));
        FACT.put(6, FACT.get(5).multiply(BigInteger.valueOf(6)));
        FACT.put(7, FACT.get(6).multiply(BigInteger.valueOf(7)));
        FACT.put(8, FACT.get(7).multiply(BigInteger.valueOf(8)));
        FACT.put(9, FACT.get(8).multiply(BigInteger.valueOf(9)));
    }

    final private static ArrayList<Long> answers = new ArrayList<Long>();

    public static void main(String[] args) {
        getAnswers();
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        long sum = 0;
        for (Long l : answers) {
            if (l > n) {
                break;
            }
            sum += l;
        }
        System.out.println(sum);
        scanner.close();
    }

    private static void getAnswers() {
        for (long i = 10; i <= 100000; i++) {
            if (isCurious(i)) {
                answers.add(i);
            }
        }
    }

    private static boolean isCurious(long i) {
        BigInteger biOriginal = BigInteger.valueOf(i);
        BigInteger bi = BigInteger.ZERO;
        while (i > 0) {
            int d = (int) (i % 10);
            bi = bi.add(FACT.get(d));
            i /= 10;
        }
        if (bi.mod(biOriginal) == BigInteger.ZERO) {
            return true;
        }
        return false;
    }

}

