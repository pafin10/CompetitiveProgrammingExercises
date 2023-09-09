import java.util.Scanner;

public class buttons {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int testCases = scanner.nextInt();
        scanner.nextLine();

        for (int i = 0; i < testCases; i++) {
            String[] buttons = scanner.nextLine().split(" ");
            int a = Integer.parseInt(buttons[0]);
            int b = Integer.parseInt(buttons[1]);
            int c = Integer.parseInt(buttons[2]);
            if (a == b) {
                if (c % 2 == 0)
                    System.out.println("Second");
                else
                    System.out.println("First");
                }
            else if (a < b)
                System.out.println("Second");
            else
                System.out.println("First");
        }
    }
}
