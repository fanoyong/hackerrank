import java.util.Scanner;

public class Solution5 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long N = scanner.nextLong();
        System.out.println(getCount(N));
        scanner.close();
    }

    private static long getCount(long N) {
        long i, j, k, count, factor;
        long SUM = (N - 1) * (N - 1);
        for (i = 2; i <= Math.sqrt(N); i++) {
            for (j = 2; j <= Math.sqrt(N); j++) {
                k = (long) Math.pow(i, j);
                if (k > N) {
                    continue;
                }
                // cout << "i=" << i << " j=" << j << " k=" << k << endl;
                factor = (long) (Math.log(k) / Math.log(i));
                count = (long) N / factor - 2 / factor;
                System.out.println("i=" + i + " j=" + j + " k=" + k + " count=" + count);
                SUM -= count;
            }
        }
        return SUM;
    }
}

