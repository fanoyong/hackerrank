
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.Scanner;

public class Solution {

    private static final boolean DEBUG = false;

    private static final Long MAX = 200000000000000L;
    private static final HashSet<Long> TRIPENTA = new HashSet<Long>();
    private static final HashSet<Long> PENTAHEXA = new HashSet<Long>();
    private static final ArrayList<Long> ANSWER = new ArrayList<Long>();

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
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        if (a == 3 && b == 5) {
            ANSWER.addAll(TRIPENTA);
            Collections.sort(ANSWER);
            for (Long l : ANSWER) {
                if (l > N) {
                    break;
                }
                System.out.println(l);
            }
        } else {
            ANSWER.addAll(PENTAHEXA);
            Collections.sort(ANSWER);
            for (Long l : ANSWER) {
                if (l > N) {
                    break;
                }
                System.out.println(l);
            }
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

