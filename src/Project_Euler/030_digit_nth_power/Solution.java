import java.util.Scanner;

public class Solution {

    private static int N;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        long answer = 0;
        switch (N) {
            case 3:
                answer = getAnswer3();
                break;
            case 4:
                answer = getAnswer4();
                break;
            case 5:
                answer = getAnswer5();
                break;
            case 6:
                answer = getAnswer6();
        }

        System.out.println(answer);
        scanner.close();
    }

    private static long getAnswer3() {
        long sum = 0, local;
        long i, j, k;
        for (i = 2; i <= 999; i++) {
            local = 0;
            k = i;
            while (k >= 1) {
                j = k % 10;
                local += j * j * j;
                k /= 10;
            }
            if (local == i) {
                sum += local;
            }
        }
        return sum;
    }

    private static long getAnswer4() {
        long sum = 0, local;
        long i, j, k;
        for (i = 2; i <= 9999; i++) {
            local = 0;
            k = i;
            while (k >= 1) {
                j = k % 10;
                local += j * j * j * j;
                k /= 10;
            }
            if (local == i) {
                sum += local;
            }
        }
        return sum;
    }

    private static long getAnswer5() {
        long sum = 0, local;
        long i, j, k;
        for (i = 2; i <= 600000; i++) {
            local = 0;
            k = i;
            while (k >= 1) {
                j = k % 10;
                local += j * j * j * j * j;
                k /= 10;
            }
            if (local == i) {
                sum += local;
            }
        }
        return sum;
    }

    private static long getAnswer6() {
        long sum = 0, local;
        long i, j, k;
        for (i = 2; i <= 999999; i++) {
            local = 0;
            k = i;
            while (k >= 1) {
                j = k % 10;
                local += j * j * j * j * j * j;
                k /= 10;
            }
            if (local == i) {
                sum += local;
            }
        }
        return sum;
    }
}

