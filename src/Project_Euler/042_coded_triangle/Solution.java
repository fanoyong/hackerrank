
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while (t-- > 0) {
            long input = scanner.nextLong();
            // Tn = n (n+1) / 2
            // n^2 + n - 2 * T = 0;
            // a x^2 + b x + c = 0;
            // x^2 + b/a x + c/a = 0;
            // (x+ b/2a)^2 - b^2/4a^2 + c/a = 0;
            // x+b/2a = sqrt(b^2-4ac)/ 2a
            // x = -b/2a +- sqrt(b^2-4ac) / 2a -> a = 1 b = 1 c = -2T
            // x = -1/2 += sqrt(1+8T) / 2

            double rate = (Math.sqrt(1 + 8 * input) - 1) / 2;
            if (rate == Math.floor(rate)) {
                System.out.println((int) rate);
            } else {
                System.out.println(-1);
            }
        }
        scanner.close();
    }
}

