import java.util.Scanner;

public class newF {
    private static Scanner input = new Scanner(System.in);
    public static void main(String[] args) {
    String str = input.nextLine();
    String ending = "izzle";
    str = str.replaceAll(" ", "izzle ");
    str = str.concat(ending);
    System.out.println(str);
    }
}
