
import java.util.Scanner;
import java.util.TreeSet;

public class Solution {

    private static final int MAX = 1000000;
    private static TreeSet<Integer> PRIMES = new TreeSet<Integer>();

    public static void main(String[] args) {
        generateAnswers();
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        scanner.close();
    }

    private static void generateAnswers() {
        for (int i = 3; i <= MAX; i += 2) {
            if (isPrime(i)) {
                PRIMES.add(i);
            }
        }
        System.out.println(PRIMES.size());
    }

    private static boolean isPrime(int i) {
        if (i < 2) {
            return false;
        } else if (i == 2 || i == 3) {
            return true;
        } else if ((i & 1) != 1) {
            return false;
        }
        for (int j = 3; i <= Math.sqrt(j); j += 2) {
            if (i % j == 0) {
                return false;
            }
        }
        return true;
    }
}

