import java.util.ArrayList;
import java.util.Scanner;

public class Solution {

    private static final String ORIGINAL = "abcd";
    private static ArrayList<String> LISTS = new ArrayList<String>();
    private static int count = 0;

    public static void main(String[] args) {
        permute_bruteforce(ORIGINAL.toCharArray(), 0, ORIGINAL.length() - 1);
        permute_better(ORIGINAL.toCharArray());
        System.out.println(count);
    }

    public static void permute_bruteforce(char[] ca, int l, int r) {
        int i;
        if (l == r) {
            // LISTS.add(new String(cs));
            count++;
        } else {
            for (i = l; i <= r; i++) {
                char c = ca[l];
                ca[l] = ca[i];
                ca[i] = c;
                permute_bruteforce(ca, l + 1, r);
                char d = ca[l];
                ca[l] = ca[i];
                ca[i] = d;
            }
        }
    }

    // 1. Find the largest index k such that a[k] < a[k + 1]. If no such index exists, the
    // permutation is the last permutation.
    // 2. Find the largest index l greater than k such that a[k] < a[l].
    // 3. Swap the value of a[k] with that of a[l].
    // 4. Reverse the sequence from a[k + 1] up to and including the final element a[n].

    public static void permute_better(char[] ca) {
        boolean isKChanged;
        int k, l;
        char c;
        do {
            isKChanged = false;
            k = 0;
            for (int i = ca.length - 2; i >= 0; i--) {
                if (ca[i] < ca[i + 1]) {
                    isKChanged = true;
                    k = i;
                }
            }
            System.out.println("k=" + k);
            l = ca.length - 1;
            for (int i = ca.length - 1; i > k; i--) {
                if (ca[i] > ca[k]) {
                    l = i;
                    break;
                }
            }
            System.out.println("l=" + l);
            System.out.println("Swap " + ca[k] + " and " + ca[l]);
            c = ca[k];
            ca[k] = ca[l];
            ca[l] = c;
            int start = k + 1;
            int last = ca.length - 1;
            while (start <= last) {
                System.out.println("Swap " + ca[start] + " and " + ca[last]);
                c = ca[start];
                ca[start] = ca[last];
                ca[last] = c;
                start++;
                last--;
            }
            System.out.println(ca);
            Scanner sc = new Scanner(System.in);
            sc.nextLine();
        } while (isKChanged);
    }

}

