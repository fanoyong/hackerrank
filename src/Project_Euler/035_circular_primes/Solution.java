
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Solution {

    final private static Set<Long> answers = new HashSet<Long>();
    static {
        answers.add((long) 2);
        answers.add((long) 3);
        answers.add((long) 5);
        answers.add((long) 7);
    }

    public static void main(String[] args) {
        getAnswers();
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        long sum = 0;
        for (Long l : answers) {
            if (l <= n) {
                sum += l;
            }
        }
        System.out.println(sum);
        scanner.close();
    }

    private static void getAnswers() {
        for (long i = 10; i <= 1000000; i++) {
            Set<Long> circles = getCircles(i);
            boolean test = true;
            if (circles == null) {
                continue;
            }
            for (Long l : circles) {
                if (!isPrime(l)) {
                    test = false;
                    break;
                }
            }
            if (test) {
                answers.addAll(circles);
            }
        }
    }

    private static Set<Long> getCircles(long l) {
        Set<Long> ret = new HashSet<Long>();
        ret.add(l);
        final int digitLength = (int) Math.log10(l) + 1;
        for (int i = 0; i < digitLength; i++) {
            int d = (int) (l % 10);
            if ((d & 1) != 1 || d == 5) {
                return null;
            }
            d *= Math.pow(10, digitLength - 1);
            l /= 10;
            l += d;
            ret.add(l);
        }
        return ret;
    }

    private static boolean isPrime(long i) {
        if (i == 2 || i == 3) {
            return true;
        }
        if ((i & 1) != 1) {
            return false;
        }
        for (long l = 3; l <= Math.sqrt(i); l += 2) {
            if (i % l == 0) {
                return false;
            }
        }
        return true;
    }
}

