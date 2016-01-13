import java.util.Scanner;

public class DataTypesPractice {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            String string = sc.nextLine();
            if (string.equalsIgnoreCase("true") || string.equalsIgnoreCase("false")) {
                System.out.println("Primitive : boolean");
                continue;
            }
            try {
                int i = Integer.parseInt(string);
                System.out.println("Primitive : int");
                continue;
            } catch (NumberFormatException e) {
            }
            try {
                double d = Double.parseDouble(string);
                System.out.println("Primitive : double");
                continue;
            } catch (NumberFormatException e) {
            }
            try {
                float f = Float.parseFloat(string);
                System.out.println("Primitive : float");
                continue;
            } catch (NumberFormatException e) {
            }
            if (string.length() == 3 && string.charAt(0) == '\'' && string.charAt(2) == '\'') {
                System.out.println("Primitive : char");
                continue;
            }
            System.out.println("Reference : String");
        }
    }

}

