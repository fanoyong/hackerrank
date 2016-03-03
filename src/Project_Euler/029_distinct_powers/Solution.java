import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long N = scanner.nextLong();
        // System.out.println(getCount(N));
        System.out.println(better(N));
        scanner.close();
    }

    private static long getCount(long N) {
        long i, j, k;
        long SUM = (N - 1) * (N - 1);
        for (i = 2; i <= Math.sqrt(N); i++) {
            for (j = 2; j <= Math.log(N) / Math.log(i) + 1; j++) {
                k = (long) Math.pow(i, j);
                if (k > N) {
                    continue;
                }
                // cout << "i=" << i << " j=" << j << " k=" << k << endl;
                int factor = (int) (Math.log(k) / Math.log(j));
                long minus = (long) (N / j) - 1;
                if (minus < 0) {
                    minus = 0;
                }
                SUM -= minus;
                System.out.println("i=" + i + " j=" + j + " k=" + k + " minus=" + minus);
            }

        }
        return SUM;
    }

    private static long better(long M) {
        int maxPow = (int) Math.floor(Math.log(M) / Math.log(2));
        long[] dupesPerPow = new long[maxPow + 1];
        long[] numOfPow = new long[maxPow + 1];
        long totDupes = 0;

        // Step one: find dupes per power.
        for (int i = 2; i <= maxPow; i++) {
            boolean[] powOverlap = new boolean[(int) (M + 1)];
            for (int k = 1; k <= i - 1; k++) {
                int spacing = lcm(k, i) / i;
                for (int n = 0; n <= k * M / i; n += spacing) {
                    powOverlap[n] = true;
                }
            }
            long count = 0;
            for (int j = 2; j <= M; j++) {
                if (powOverlap[j])
                    count++;
            }
            dupesPerPow[i] = count;
        }

        // Step two: find actual number of powers.
        int sqrtN = (int) Math.pow(M, 0.5);
        boolean[] powersNotToRepeat = new boolean[sqrtN + 1];
        for (int i = 2; i <= sqrtN; i++) {
            if (!powersNotToRepeat[i]) {
                for (int p = 2; Math.pow(i, p) <= M; p++) {
                    numOfPow[p]++;
                    if (Math.pow(i, p) <= sqrtN)
                        powersNotToRepeat[(int) Math.pow(i, p)] = true;
                }
            }
        }

        for (int p = 2; p <= maxPow; p++) {
            totDupes += numOfPow[p] * dupesPerPow[p];
        }
        return (M - 1) * (M - 1) - totDupes;
    }

    public static int lcm(int k, int i) { // Use Euclidean algo for GCD to get LCM.
        // assert k < i
        if (i % k == 0)
            return i;
        else {
            int i_ = i;
            int k_ = k; // store original values
            int r = i % k;
            while (r != 0) {
                i = k;
                k = r;
                r = i % k;
            }
            return i_ * k_ / k;
        }
    }
}

// 2^2 2^3 2^4 2^5 2^6 2^7 2^8 2^9 2^10
// 3^2 3^3 3^4 3^5 3^6 3^7 3^8 3^9 3^10
// 4^2 4^3 4^4 4^5 4^6 4^7 4^8 4^9 4^10
// 5^2 5^3 5^4 5^5 5^6 5^7 5^8 5^9 5^10
// 6^2 6^3 6^4 6^5 6^6 6^7 6^8 6^9 6^10
// 7^2 7^3 7^4 7^5 7^6 7^7 7^8 7^9 7^10
// 8^2 8^3 8^4 8^5 8^6 8^7 8^8 8^9 8^10
// 9^2 9^3 9^4 9^5 9^6 9^7 9^8 9^9 9^10
// 10^2 10^3 10^4 10^5 10^6 10^7 10^8 10^9 10^10
// 10
// 2 - 4 4
// 2 - 8 2
// 3 - 9 4

