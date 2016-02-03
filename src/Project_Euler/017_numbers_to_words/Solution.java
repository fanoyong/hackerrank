import java.io.*;
import java.util.*;

public class Solution {

    private static final ArrayList<String> ONES = new ArrayList<String>();

    static {
        ONES.add("One");
        ONES.add("Two");
        ONES.add("Three");
        ONES.add("Four");
        ONES.add("Five");
        ONES.add("Six");
        ONES.add("Seven");
        ONES.add("Eight");
        ONES.add("Nine");
        ONES.add("Ten");
        ONES.add("Eleven");
        ONES.add("Twelve");
        ONES.add("Thirteen");
        ONES.add("Fourteen");
        ONES.add("Fifteen");
        ONES.add("Sixteen");
        ONES.add("Seventeen");
        ONES.add("Eighteen");
        ONES.add("Nineteen");
    };

    private static final ArrayList<String> TENS = new ArrayList<String>();

    static {
        TENS.add("Twenty");
        TENS.add("Thirty");
        TENS.add("Forty");
        TENS.add("Fifty");
        TENS.add("Sixty");
        TENS.add("Seventy");
        TENS.add("Eighty");
        TENS.add("Ninety");
    }

    private static final String HUNDRED = "Hundred";

    private static final ArrayList<String> THOUSANDS = new ArrayList<String>();

    static {
        THOUSANDS.add("Thousand");
        THOUSANDS.add("Million");
        THOUSANDS.add("Billion");
        THOUSANDS.add("Trillion");
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        while (T-- > 0) {
            long N = scanner.nextLong();
            if (N == 0) {
                System.out.println("Zero");
                continue;
            }
            long remainder;
            StringBuilder sb = new StringBuilder();
            while (N > 0) {
                if (N >= 1000000000000l) {
                    remainder = (long) (N / (1000000000000l));
                    sb.append(getStringForLong((int) remainder) + " " + THOUSANDS.get(3) + " ");
                    N %= (1000000000000l);
                } else if (N >= 1000000000) {
                    remainder = (long) (N / (1000000000));
                    sb.append(getStringForLong((int) remainder) + " " + THOUSANDS.get(2) + " ");
                    N %= (1000000000);
                } else if (N >= 1000000) {
                    remainder = (long) (N / (1000000));
                    sb.append(getStringForLong((int) remainder) + " " + THOUSANDS.get(1) + " ");
                    N %= (1000000);
                } else if (N >= 1000) {
                    remainder = (long) (N / 1000);
                    sb.append(getStringForLong((int) remainder) + " " + THOUSANDS.get(0) + " ");
                    N %= (1000);
                } else {
                    sb.append(getStringForLong((int) N));
                    N = 0;
                }
            }
            System.out.println(sb.toString().trim());
        }
        scanner.close();
    }

    private static String getStringForLong(int remainder) {
        StringBuilder sb = new StringBuilder();
        while (remainder > 0) {
            if (remainder >= 100) {
                int hundreds = (int) (remainder / 100);
                sb.append(ONES.get(hundreds - 1) + " Hundred");
                remainder -= hundreds * 100;
            } else if (remainder >= 20) {
                int tens = (int) (remainder / 10);
                sb.append(TENS.get(tens - 2));
                remainder -= tens * 10;
            } else {
                sb.append(ONES.get(remainder - 1));
                remainder = 0;
            }
            sb.append(" ");
        }
        return sb.toString().trim();
    }
}

