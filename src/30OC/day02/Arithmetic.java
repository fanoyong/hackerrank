import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Arithmetic {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        float M = sc.nextFloat(); // original meal price
        int T = sc.nextInt(); // tip percentage
        int X = sc.nextInt(); // tax percentage
        int price = Math.round(M * (T+X+100) / 100);
        
        System.out.println("The final price of the meal is $" + price + ".");
    }
}
