
import java.util.HashMap;
import java.util.Scanner;

public class Solution {

    private static HashMap<Long, Integer> answers = new HashMap<Long, Integer>();

    public static void main(String[] args) {
        getMaxPerimeter();
        System.out.println("data generated");
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while (t-- > 0) {
            Long n = scanner.nextLong();
        }
        scanner.close();
    }

    private static void getMaxPerimeter() {
        int maxcount = 0;
        for (long p = 2; p <= 10000; p++) {
            int count = 0;
            for (long a = 2; a < (p / 3); a++) {
                if (p * (p - 2 * a) % (2 * (p - a)) == 0) {
                    count++;
                }
            }
            if (count > maxcount) {
                answers.put(p, count);
            }
        }
    }
}

