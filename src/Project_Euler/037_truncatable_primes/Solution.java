
import java.util.ArrayList;
import java.util.Scanner;

public class Solution {

    private static ArrayList<Long> answer = new ArrayList<Long>();
    private static boolean[] sieve = new boolean[1000001];

    public static void main(String[] args) {
        // generateData();
        generateData2();
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        long sum = 0;
        for (int i = 0; i < answer.size(); i++) {
            long d = answer.get(i);
            if (d > n) {
                break;
            }
            sum += d;
        }
        System.out.println(sum);
        scanner.close();
    }

    private static void generateData2() {
        for (int i = 0; i <= 1000000; i++) {
            sieve[(int) i] = true;
        }
        sieve[0] = false;
        sieve[1] = false;
        for (int i = 2; i <= Math.sqrt(1000000); i++) {
            if (sieve[i]) {
                for (int j = i * 2; j <= 1000000; j += i) {
                    sieve[j] = false;
                }
            }
        }
        for (long i = 11; i < 1000000; i += 2) {
            if (!sieve[(int) i]) {
                continue;
            }
            boolean DEBUG = false;
            long digits = (int) (Math.log10(i));
            long div = (int) Math.pow(10, digits);
            if (DEBUG) {
                System.out.println("div: " + div);
            }
            long t = i % div;
            boolean isDirty = true;
            while (div > 0 && t > 0) {
                if (DEBUG) {
                    System.out.println("t1: " + t);
                }
                if (!sieve[(int) t]) {
                    isDirty = false;
                    break;
                }
                div /= 10;
                if (div > 0) {
                    t = i % div;
                }
            }
            if (!isDirty) {
                continue;
            }
            t = (int) i / 10;
            while (t > 0) {
                if (DEBUG) {
                    System.out.println("t2: " + t);
                }
                if (!sieve[(int) t]) {
                    isDirty = false;
                    break;
                }
                t /= 10;
            }
            if (!isDirty) {
                continue;
            }
            System.out.println("d:" + i);
            answer.add(i);
        }
    }

    private static void generateData() {
        for (long i = 11; i < 1000000; i += 2) {
            long digits = (int) (Math.log10(i));
            long div = (int) Math.pow(10, digits);
            long t = i % div;
            boolean isDirty = true;
            while (div > 0 && t > 0) {
                if (!isPrime(t)) {
                    isDirty = false;
                    break;
                }
                div /= 10;
                if (div > 0) {
                    t = i % div;
                }
            }
            if (!isDirty) {
                continue;
            }
            t = (int) i / 10;
            while (t > 0) {
                if (!isPrime(t)) {
                    isDirty = false;
                    break;
                }
                t /= 10;
            }
            if (!isDirty) {
                continue;
            }
            System.out.println("d:" + i);
            answer.add(i);
        }
    }

    private static boolean isPrime(long n) {
        if (n <= 1) {
            return false;
        }
        if (n == 2 || n == 3) {
            return true;
        }
        if ((n & 1) != 1) {
            return false;
        }
        for (long i = 3; i <= Math.sqrt(n); i += 2) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
}

