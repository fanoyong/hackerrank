
import java.util.ArrayList;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class Solution {

    private static final boolean DEBUG = false;

    private static final int MAX = 1000000;
    private static Set<String> ANSWER = new TreeSet<String>();
    private static final boolean PRIMEMAP[] = new boolean[MAX + 1];
    private static ArrayList<Integer> PRIMES = new ArrayList<Integer>();

    public static void main(String[] args) {
        generateAnswers();
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        if (K == 3) {
            getAnswer3(N);
        } else {
            getAnswer4(N);
        }
        for (String s : ANSWER) {
            System.out.println(s);
        }
        scanner.close();
    }

    private static void getAnswer3(int n) {
        for (int i = 0; i < PRIMES.size(); i++) {
            int p1 = PRIMES.get(i);
            if (p1 >= n) {
                break;
            }
            for (int j = i + 1; j < PRIMES.size(); j++) {
                int p2 = PRIMES.get(j);
                if (!isPerm(p1, p2)) {
                    continue;
                }
                int gap = p2 - p1;
                int p3 = p2 + gap;
                if (p3 >= MAX) {
                    break;
                }
                if (!isPerm(p1, p3)) {
                    continue;
                }
                if (PRIMEMAP[p3]) {
                    StringBuffer sb = new StringBuffer();
                    sb.append(p1);
                    sb.append(p2);
                    sb.append(p3);
                    ANSWER.add(sb.toString());
                }
            }
        }
    }

    private static void getAnswer4(int n) {
        for (int i = 0; i < PRIMES.size(); i++) {
            int p1 = PRIMES.get(i);
            if (p1 >= n) {
                break;
            }
            for (int j = i + 1; j < PRIMES.size(); j++) {
                int p2 = PRIMES.get(j);
                if (!isPerm(p1, p2)) {
                    continue;
                }
                int gap = p2 - p1;
                int p3 = p2 + gap;
                if (p3 >= MAX) {
                    break;
                }
                if (!isPerm(p1, p3)) {
                    continue;
                }
                int p4 = p3 + gap;
                if (p4 >= MAX) {
                    break;
                }
                if (!isPerm(p1, p4)) {
                    continue;
                }
                if (PRIMEMAP[p4]) {
                    StringBuffer sb = new StringBuffer();
                    sb.append(p1);
                    sb.append(p2);
                    sb.append(p3);
                    ANSWER.add(sb.toString());
                }
            }
        }
    }

    private static void generateAnswers() {
        for (int i = 0; i <= MAX; i++) {
            PRIMEMAP[i] = false;
        }
        int count = 1001;
        do {
            if (isPrime(count)) {
                PRIMEMAP[(int) count] = true;
                PRIMES.add(count);
            }
            count += 2;
        } while (count <= MAX);
        if (DEBUG) {
            System.out.println("PRIME size: " + PRIMES.size());
        }
    }

    private static boolean isPrime(long i) {
        if (i < 2) {
            return false;
        } else if (i == 2 || i == 3) {
            return true;
        } else if ((i & 1) != 1) {
            return false;
        }
        long j = 3;
        while (j <= Math.sqrt(i)) {
            if (i % j == 0) {
                return false;
            }
            j += 2;
        }
        return true;
    }

    private static boolean isPerm(int a, int b) {
        int[] count1 = new int[10];
        int[] count2 = new int[10];
        for (int i = 0; i < 10; i++) {
            count1[i] = 0;
            count2[i] = 0;
        }
        while (a > 0) {
            count1[a % 10]++;
            a /= 10;
        }
        while (b > 0) {
            count2[b % 10]++;
            b /= 10;
        }
        for (int i = 0; i < 10; i++) {
            if (count1[i] != count2[i]) {
                return false;
            }
        }
        return true;
    }
}

