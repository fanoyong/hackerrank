
import java.util.Scanner;
import java.util.TreeSet;

public class Solution {

    private static final boolean DEBUG = true;

    private static final Long MAX = 200000000000000L;
    private static final TreeSet<Long> TRIPENTA = new TreeSet<Long>();
    private static final TreeSet<Long> PENTAHEXA = new TreeSet<Long>();

    public static void main(String[] args) {
        generateAnswers();
        Scanner scanner = new Scanner(System.in);
        if (DEBUG) {
            System.out.println("TRIPENTA:" + TRIPENTA.size());
            for (Long l : TRIPENTA) {
                System.out.println(l);
            }
            System.out.println("PENTAHEXA:" + PENTAHEXA.size());
            for (Long l : PENTAHEXA) {
                System.out.println(l);
            }
        }
        long N = scanner.nextLong();
        long a = scanner.nextLong();
        long b = scanner.nextLong();
        if (a == 3 && b == 5) {
            for (Long l : TRIPENTA) {
                if (l >= N) {
                    break;
                }
                System.out.println(l);
            }
        } else if (a == 5 && b == 6) {
            for (Long l : PENTAHEXA) {
                if (l >= N) {
                    break;
                }
                System.out.println(l);
            }
        } else {
            long n = 1;
            do {
                long x = n * (2 * n - 1);
                if (x >= N) {
                    break;
                }
                System.out.println(x);
                n++;
            } while (true);
        }
        scanner.close();
    }

    private static void generateAnswers() {
        long n = 1;
        do {
            long x = n * (n + 1) / 2;
            if (x > MAX) {
                break;
            }
            if (isPentagonal(x)) {
                TRIPENTA.add(x);
            }
            n++;
        } while (true);
        n = 1;
        do {
            long x = n * (2 * n - 1);
            if (x > MAX) {
                break;
            }
            if (isPentagonal(x)) {
                PENTAHEXA.add(x);
            }
            n++;
        } while (true);
    }

    private static boolean isPentagonal(long number) {
        double penTest = (Math.sqrt(1 + 24 * number) + 1.0) / 6.0;
        return penTest == ((long) penTest);
    }

}

