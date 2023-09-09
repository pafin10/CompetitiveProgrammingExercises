import java.util.ArrayList;
import java.util.Scanner;

public class Beautiful_Matrix {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ArrayList<Integer> entries = new ArrayList<>();
        int row_1 = 0;
        int column_1 = 0;
        for (int i = 0; i < 25; i++) {
            entries.add(scanner.nextInt());
        }
        scanner.nextLine();
        // Two cases: 1. matrix is already beautiful
        int [][] matrix = new int[5][5];
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                matrix[i][j] = entries.get(i*5 + j);
                if (matrix[i][j] == 1) {
                    row_1 = i;
                    column_1 = j;
                    break;
                }
            }
        }
        if (matrix[2][2] == 1) {
            System.out.println(0);
            System.exit(0);
        }

        // 2. matrix is not beautiful and must be transformed
        // if in same line, either 1 or 2 transformations
        if (row_1 == 2 || column_1 == 2) {
            if (row_1 == 0 || row_1 == 4 || column_1 == 0 || column_1 == 4) {
                System.out.println(2);
                System.exit(0);
            }
            else {
                System.out.println(1);
                System.exit(0);
            }
        }
        // if different line, either 3 or 4: check edge cases
        if ((row_1 == 0 || row_1 == 4) && (column_1 == 0 || column_1 == 4)) {
            System.out.println(4);
            System.exit(0);
        }
        else if ((row_1 == 1 || row_1 == 3) && (column_1 ==1 || column_1 == 3)) {
            System.out.println(2);
            System.exit(0);
        }
        System.out.println(3);
    }
}
