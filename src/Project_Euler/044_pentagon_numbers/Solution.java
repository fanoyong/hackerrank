import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.Scanner;

public class Solution {

    private static final int MAX = 1000001;
    private static HashSet<Long> PENTAGONAL = new HashSet<Long>();
    private static HashSet<Long> PENTAGONAL_MINUS = new HashSet<Long>();
    private static HashSet<Long> PENTAGONAL_PLUS = new HashSet<Long>();
    private static long[] PENTAGONAL_ORIGINAL = new long[MAX];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        for (int i = 1; i <= N; i++) {
            long l2 = i;
            long l = (3 * l2 * l2 - l2) / 2;
            PENTAGONAL_ORIGINAL[i] = l;
            PENTAGONAL.add(l);
        }
        ArrayList<Long> RET = new ArrayList<Long>();
        for (int i = K + 1; i <= N; i++) {
            if (PENTAGONAL.contains(PENTAGONAL_ORIGINAL[i] + PENTAGONAL_ORIGINAL[i - K])) {
                PENTAGONAL_PLUS.add(PENTAGONAL_ORIGINAL[i]);
            }
            if (PENTAGONAL.contains(PENTAGONAL_ORIGINAL[i] - PENTAGONAL_ORIGINAL[i - K])) {
                PENTAGONAL_MINUS.add(PENTAGONAL_ORIGINAL[i]);
            }
        }
        PENTAGONAL_MINUS.addAll(PENTAGONAL_PLUS);
        PENTAGONAL_MINUS.retainAll(PENTAGONAL);

        RET.addAll(PENTAGONAL_MINUS);
        Collections.sort(RET);
        for (Long l : RET) {
            System.out.println(l);
        }
        scanner.close();
    }
}
