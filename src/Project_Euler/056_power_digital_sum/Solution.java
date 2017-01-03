import java.math.BigInteger;
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.close();
        int ret = getAnswer(n);
        System.out.println(ret);
    }

    private static int getAnswer(int n) {
        int ret = Integer.MIN_VALUE;
        for (int i = n - 1; i >= 2; i--) {
            for (int j = n - 1; j >= 2; j--) {
                int base = i;
                BigInteger bi = BigInteger.valueOf(base);
                String str = bi.pow(j).toString();
                char[] cs = str.toCharArray();
                int count = 0;
                for (int k = 0; k < str.length(); k++) {
                    count += cs[k] - '0';
                }
                if (count > ret) {
                    ret = count;
                }
            }
        }
        return ret;
    }
}

