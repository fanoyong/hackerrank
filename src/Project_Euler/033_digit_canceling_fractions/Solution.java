package com.fanoyong.projecteuler;

import java.util.HashMap;
import java.util.Scanner;
import java.util.Set;

public class Solution {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = 2;
        int K = 1;
        long asum = 0;
        long bsum = 0;
        // final int start = (int) Math.pow(10, N - 1);
        final int start = 1;
        final int end = (int) Math.pow(10, N) - 1;
        for (int i = start; i <= end; i++) {
            
            Number a = new Number(i);
            for (int j = start; j <= end; j++) {
                Number b = new Number(j);
                if (isSame(a, b, K)) {
                    asum += i;
                    bsum += j;
                }
            }
        }
        System.out.println(asum + " " + bsum);
        scanner.close();
    }

    private static boolean isSame(Number a, Number b, int K) {
        HashMap<Integer, Integer> digita = a.getDigit();
        HashMap<Integer, Integer> digitb = b.getDigit();
        Set<Integer> keya = digita.keySet();
        Set<Integer> keyb = digitb.keySet();
        for (Integer)
        return false;
    }

    private static class Number {
        private int mNumber;
        private HashMap<Integer, Integer> digit = new HashMap<Integer, Integer>();

        public Number(int A) {
            mNumber = A;
            int d = A % 10;
            if (!digit.containsKey(d)) {
                digit.put(d, 1);
            } else {
                digit.put(d, digit.get(d) + 1);
            }
            A /= 10;
        }

        public int getNumber() {
            return mNumber;
        }

        public HashMap<Integer, Integer> getDigit() {
            return digit;
        }
    }

}
