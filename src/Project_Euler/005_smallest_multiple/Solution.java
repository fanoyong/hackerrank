import java.util.HashMap;
import java.util.Scanner;

import javax.lang.model.type.NullType;

public class Solution {

    private static HashMap<Integer, Integer> PrimeFactor = new HashMap<Integer, Integer>();

    private static void generateList(int N) {
        for (int i = 2; i <= N; i++) {
            int n = i;
            while (n != 1) {
                for (int j = 2; j <= i; j++) {
                    int cnt = 0;
                    while (n % j == 0) {
                        cnt++;
                        n /= j;
                    }
                    if (PrimeFactor.get(j) == null) {
                        PrimeFactor.put(j, cnt);
                    } else if (PrimeFactor.get(j) < cnt) {
                        PrimeFactor.put(j, cnt);
                    }
                }
            }
        }
    }

    public static void main(String[] args) {
        int T, N;
        Scanner sc = new Scanner(System.in);
        T = sc.nextInt();
        while (T-- > 0) {
            PrimeFactor.clear();
            N = sc.nextInt();
            generateList(N);
            printAnswer();
        }
    }

    private static void printAnswer() {
        int answer = 1;
        for(Integer key: PrimeFactor.keySet()) {
            Integer val = PrimeFactor.get(key);
            if(val != null && val > 0) {
                answer *= Math.pow(key, val);
            }
        }
        System.out.println(answer);
    }

}

