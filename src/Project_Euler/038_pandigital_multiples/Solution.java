
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        generateAnswer(n, k);
        scanner.close();
    }

    private static void generateAnswer(int n, int k) {
        boolean DEBUG = false;
        for (int i = 2; i <= 10000; i++) {
            if (i > n) {
                break;
            }
            boolean[] count = new boolean[10];
            for (int j = 1; j <= k; j++) {
                count[j] = false;
            }
            // 13728
            // 27456
            boolean isPandigital = true;
            for (int j = 1; j <= 9; j++) {
                int prod = i * j;
                while (prod > 0) {
                    int d = prod % 10;
                    if (d > k || d == 0) {
                        isPandigital = false;
                        break;
                    }
                    if (count[d]) {
                        if (DEBUG) {
                            System.out.println("j=" + j + " prod=" + prod);
                        }
                        isPandigital = false;
                        break;
                    }
                    count[d] = true;
                    if (DEBUG) {
                        System.out.println("prod:" + prod);
                        System.out.println("d:" + d);
                        print(count, 9);
                    }
                    prod /= 10;
                }
                if (!isPandigital) {
                    if (DEBUG) {
                        System.out.println("first break");
                    }
                    break;
                }
                boolean allmarked = true;
                for (int l = 1; l <= k; l++) {
                    if (!count[l]) {
                        allmarked = false;
                    }
                }
                if (allmarked) {
                    if (DEBUG) {
                        System.out.println("second break");
                    }
                    j = 10;
                    break;
                }
            }
            if (isPandigital) {
                System.out.println(i);
            }
        }
    }

    /**
     * 9 18 27 36 45
     * 
     * @param arr
     * @param count
     */
    private static void print(boolean[] arr, int count) {
        for (int i = 1; i <= count; i++) {
            System.out.print(" " + arr[i] + " ");
        }
        System.out.println();
    }
}

