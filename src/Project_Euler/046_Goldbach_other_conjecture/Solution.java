
import java.util.Scanner;
import java.util.TreeSet;

public class Solution {

    private static final int MAX = 500000;
    private static final TreeSet<Long> PRIMES = new TreeSet<Long>();
    private static final TreeSet<Long> TWICE = new TreeSet<Long>();

    public static void main(String[] args) {
        generateAnswers();
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        while (T-- > 0) {
            int N = scanner.nextInt();
            if (N < 9 || (N & 1) != 1 || isPrime(N)) {
                System.out.println(0);
                continue;
            }
            System.out.println(getCount(N));
        }
        scanner.close();
    }

    private static int getCount(int N) {
        int count = 0;
        for (Long twice : TWICE) {
            if (twice > N) {
                break;
            }
            if (PRIMES.contains(N - twice)) {
                count++;
            }
        }
        return count;
    }

    private static void generateAnswers() {
        PRIMES.add(2L);
        for (int i = 3; i <= MAX; i += 2) {
            if (isPrime(i)) {
                PRIMES.add((long) i);
            }
        }
        long x = 1;
        do {
            long y = 2 * x * x;
            x++;
            if (y > MAX) {
                break;
            }
            TWICE.add(y);
        } while (true);
    }

    private static boolean isPrime(int A) {
        if (A <= 1) {
            return false;
        } else if (A == 2 || A == 3) {
            return true;
        } else if ((A & 1) != 1) {
            return false;
        }
        for (int i = 3; i <= Math.sqrt(A); i += 2) {
            if (A % i == 0) {
                return false;
            }
        }
        return true;
    }

    private static boolean isTwiceSquare(long number) {
        double squareTest = Math.sqrt(number / 2);
        return squareTest == ((int) squareTest);
    }
}

