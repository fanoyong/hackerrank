
import java.util.ArrayList;
import java.util.Scanner;

public class Solution {

    private static ArrayList<Integer> answers = new ArrayList<Integer>();

    public static void main(String[] args) {
        generateData();
        System.out.println("data generated");
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while (t-- > 0) {
            int n = scanner.nextInt();
            System.out.println("data generated");
        }
        scanner.close();
    }

    private static int iprev = 0;

    private static void generateData() {
        int cur = 0;
        for (int i = 12; i < 5000; i++) {
            int max = getMaxPerimeter(i);
            if (max > cur) {
                cur = max;
                answers.add(cur);
            }
        }
    }

    // a+b+c <= n
    // a^2 + b^2 = c^2
    private static int getMaxPerimeter(int n) {
        int maxp = n;
        int maxcount = 0;
        for (int p = iprev; p <= n; p++) {
            int count = 0;
            for (int a = 1; a < p / 2; a++) {
                int asq = a * a;
                for (int b = 1; b <= a; b++) {
                    int c = p - a - b;
                    if (c > a + b) {
                        continue;
                    }
                    int bsq = b * b;
                    int csq = c * c;
                    if (asq + bsq == csq) {
                        count++;
                    }
                }
            }
            if (count > maxcount) {
                iprev = p;
                maxcount = count;
                maxp = p;
            }
        }
        return maxp;
    }
}

