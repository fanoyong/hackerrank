
import java.util.Scanner;
import java.util.TreeSet;

public class Solution {

    private static final int MAX = 500000;
    private static final TreeSet<Long> PRIMES = new TreeSet<Long>();
    private static final TreeSet<Long> TWICE = new TreeSet<Long>();

    public static void main(String[] args) {
        generateAnswers();
import java.util.Scanner;
import java.util.TreeSet;

public class Solution {

    private static final int MAX = 2000000;
    private static int[] COUNT = new int[MAX + 4];
    private static final TreeSet<Integer> PRIMES = new TreeSet<Integer>();

    public static void main(String[] args) {
        generateAnswers();
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        for (int i = 1; i <= N; i++) {
            if (COUNT[i] != K) {
                continue;
            }
            boolean flag = true;
            for (int j = i + 1; j <= i + K - 1; j++) {
                if (COUNT[j] != K) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                System.out.println(i);
            }
        }
        scanner.close();
    }

    private static void generateAnswers() {
        PRIMES.add(2);
        for (int i = 3; i <= MAX; i += 2) {
            if (isPrime(i)) {
                PRIMES.add(i);
            }
        }
        for (int i = 0; i <= MAX + 3; i++) {
            COUNT[i] = 0;
        }
        for (int prime : PRIMES) {
            for (int sieve = prime; sieve <= MAX; sieve += prime) {
                COUNT[sieve]++;
            }
        }
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

}

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

