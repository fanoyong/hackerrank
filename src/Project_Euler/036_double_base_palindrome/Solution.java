
import java.util.ArrayList;
import java.util.Scanner;

public class Solution {

    private static ArrayList<Long> answer = new ArrayList<Long>();

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        long k = scanner.nextLong();
        long sum = generateAnswer(n, k);
        System.out.println(sum);
        scanner.close();
    }

    private static long generateAnswer(long n, long k) {
        long sum = 0;
        for (long i = 1; i <= 9; i++) {
            String translated = Long.toString(i, (int) k);
            char[] chars = translated.toCharArray();
            int start = 0;
            int end = translated.length() - 1;
            boolean isPanlindrome = true;
            while (start < end) {
                if (chars[start++] != chars[end--]) {
                    isPanlindrome = false;
                    break;
                }
            }
            if (isPanlindrome) {
                System.out.println("i: " + i + " translated: " + translated);
                sum += i;
                answer.add(i);
            }
        }
        for (long i = 11; i <= n; i++) {
            String base10s = Long.toString(i);
            char[] base10 = base10s.toCharArray();
            int start = 0;
            int end = base10s.length() - 1;
            boolean isPanlindrome = true;
            while (start < end) {
                if (base10[start++] != base10[end--]) {
                    isPanlindrome = false;
                    break;
                }
            }
            if (!isPanlindrome) {
                continue;
            }
            String translated = Long.toString(i, (int) k);
            char[] chars = translated.toCharArray();
            start = 0;
            end = translated.length() - 1;
            isPanlindrome = true;
            while (start < end) {
                if (chars[start++] != chars[end--]) {
                    isPanlindrome = false;
                    break;
                }
            }
            if (isPanlindrome) {
                System.out.println("i: " + i + " translated: " + translated);
                sum += i;
                answer.add(i);
            }
        }
        return sum;
    }
}

