import java.util.Scanner;

public class hamburger {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int testCases = scanner.nextInt();
        scanner.nextLine();

        int [] layers = new int[testCases];
        int count = 0;
        for (int i = 0; i < testCases; i++) {
            String line = scanner.nextLine().trim();
            String [] ints = line.split(" ");

            int breads = Integer.parseInt(ints[0]);
            int cheese = Integer.parseInt(ints[1]);
            int ham = Integer.parseInt(ints[2]);
            layers[count] = layerCalculator(breads, cheese, ham);
            count ++;
        }
        for (int num: layers)
            System.out.println(num);
    }

    public static int layerCalculator(int breads, int cheese, int ham) {
        int count = 0;
        while (breads > 1 && (cheese != 0 || ham != 0)) {
            breads --;
            count++;
            if (cheese == 0)
                ham--;
            else
                cheese--;
            count++;
        }
        // last layer of bread
        count++;
        return count;
    }
}
