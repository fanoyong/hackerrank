import java.math.BigInteger;
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        int[] count = new int[100001];
        for (int i = 1; i <= 100000; i++) {
            BigInteger cur = BigInteger.valueOf(i);
            for (int j = 0; j < 60; j++) {
                if (isPanlindrome(cur)) {
                    if (cur.equals(BigInteger.valueOf(121))) {
                        System.out.println(i);
                    }
                    if (cur.compareTo(BigInteger.valueOf(100000)) <= 0) {
                        count[cur.intValue()]++;
                    }
                    break;
                }
                cur = cur.add(getReverse(cur));
            }
        }
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.close();
        int max = Integer.MIN_VALUE;
        int maxi = 0;
        for (int i = 1; i <= n; i++) {
            if (count[i] > max) {
                max = count[i];
                maxi = i;
            }
        }
        System.out.println(maxi + " " + max);
    }

    private static BigInteger getReverse(BigInteger n) {
        String ns = String.valueOf(n);
        StringBuilder sb = new StringBuilder(ns);
        return new BigInteger(sb.reverse().toString());
    }

    private static boolean isPanlindrome(BigInteger n) {
        if (n.compareTo(BigInteger.TEN) < 0) {
            return true;
        }
        String ns = String.valueOf(n);
        char[] nsc = ns.toCharArray();
        int start = 0;
        int end = ns.length() - 1;
        while (start < end) {
            if (nsc[start++] != nsc[end--]) {
                return false;
            }
        }
        return true;
    }
}

