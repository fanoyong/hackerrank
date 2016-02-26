import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class Solution {

    private static HashMap<Integer, Integer> DATA = new HashMap<Integer, Integer>();

    public static void main(String[] args) {
        int T, N;
        Scanner sc = new Scanner(System.in);
        generateData();
        T = sc.nextInt();
        while (T-- > 0) {
            N = sc.nextInt();
            System.out.println(getAnswer(N));
        }
        sc.close();
    }

    private static void generateData() {
        int n, q, index;
        ArrayList<Integer> list = new ArrayList<Integer>();
        for (int i = 3; i <= 10000; i++) {
            n = 1;
            if (i % 5 == 0) {
                DATA.put(i, 0);
                continue;
            }
            index = 0;
            while (true) {
                while (n < i) {
                    n *= 10;
                }
                n %= i;
                // System.out.println("i:" + i + " n:" + n);
                if (n == 0) {
                    index = 0;
                    break;
                }
                if (list.contains(n)) {
                    index = list.indexOf(n);
                    break;
                }
                list.add(n);
            }
            DATA.put(i, list.size() - index);
            list.clear();
        }
    }

    private static int getAnswer(int N) {
        int MAX = Integer.MIN_VALUE;
        int index = 1;
        for (int i = 3; i <= N; i++) {
            if (DATA.get(i) != null && DATA.get(i) > MAX) {
                MAX = DATA.get(i);
                index = i;
            }
        }
        return index;
    }
}

