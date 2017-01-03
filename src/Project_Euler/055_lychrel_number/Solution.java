import java.math.BigInteger;
import java.util.HashMap;
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        HashMap<BigInteger, Integer> answer = new HashMap<BigInteger, Integer>();
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.close();
        for (int i = 1; i <= n; i++) {
            BigInteger cur = BigInteger.valueOf(i);
            for (int j = 0; j < 60; j++) {
                if (isPanlindrome(cur)) {
                    if (answer.containsKey(cur)) {
                        int count = answer.get(cur);
                        answer.put(cur, count + 1);
                    } else {
                        answer.put(cur, 1);
                    }
                    break;
                }
                cur = cur.add(getReverse(cur));
            }
        }
        int max = Integer.MIN_VALUE;
        BigInteger maxi = BigInteger.ZERO;
        for (BigInteger bi : answer.keySet()) {
            int ans = answer.get(bi);
            if (ans > max) {
                max = ans;
                maxi = bi;
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

