import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = Integer.parseInt(sc.nextLine());
        ArrayList<BigDecimal> bds = new ArrayList<BigDecimal>();
        ArrayList<String> bds_s = new ArrayList<String>();
        while (T-- > 0) {
            String input = sc.nextLine();
            BigDecimal bd = new BigDecimal(input);
            bds_s.add(input);
            bds.add(bd);
        }
        Collections.sort(bds, new Comparator<BigDecimal>() {
            @Override
            public int compare(BigDecimal arg0, BigDecimal arg1) {
                return (arg0.compareTo(arg1)) < 0 ? 1 : -1;
            }
        });
        for (BigDecimal bigd : bds) {
            for (String str : bds_s) {
                if (new BigDecimal(str).equals(bigd)) {
                    System.out.println(str);
                    break;
                }
            }
        }
    }
}

