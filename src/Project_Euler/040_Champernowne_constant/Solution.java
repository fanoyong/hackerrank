
import java.util.Scanner;

public class Solution {

    private static final boolean DEBUG = true;

    private static long[] LENGTH = new long[18];
    private static long[] FACTOR = new long[18];
    private static long[] COUNT = new long[18];
    private static long[] START = new long[18];

    public static void main(String[] args) {
        LENGTH[0] = 1;
        FACTOR[0] = 1;
        COUNT[0] = 9;
        START[0] = 0;
        generateData();
        if (DEBUG) {
            for (int i = 0; i < 18; i++) {
                System.out.println("LENGTH" + LENGTH[i]);
                System.out.println("COUNT:" + COUNT[i]);
                System.out.println("START:" + START[i]);
            }
        }
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while (t-- > 0) {
            long d1 = getDigit(scanner.nextLong());
            long d2 = getDigit(scanner.nextLong());
            long d3 = getDigit(scanner.nextLong());
            long d4 = getDigit(scanner.nextLong());
            long d5 = getDigit(scanner.nextLong());
            long d6 = getDigit(scanner.nextLong());
            long d7 = getDigit(scanner.nextLong());
            long answer = d1 * d2 * d3 * d4 * d5 * d6 * d7;
            System.out.println(answer);
        }
        scanner.close();
    }

    private static void generateData() {
        for (int i = 1; i < 18; i++) {
            LENGTH[i] = i + 1;
            FACTOR[i] = FACTOR[i - 1] * 10;
            COUNT[i] = FACTOR[i] * 9;
            START[i] = START[i - 1] + LENGTH[i - 1] * COUNT[i - 1];
        }
    }

    // Assume 1 index for array
    // 1-9 : 9 starts from 1
    // 10-99: 90 starts from 10 to 90*2
    // 100-999: 900 start from 100 to 900*2
    // 1000-9999: 9000 starts from 1000
    private static int getDigit(long d) {
        int length = 0;
        while (d > START[length]) {
            length++;
        }
        length--;
        long relativeStart = START[length];
        long relativePosition = d - START[length];
        int whichDigit = (int) (relativePosition % (FACTOR[length] * 10));
        if (DEBUG) {
            System.out.println(relativeStart);
            System.out.println(relativePosition);
            System.out.println(whichDigit);
        }
        return 0;
    }

}

