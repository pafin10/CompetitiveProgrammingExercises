package _800;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class InfinityTable_naive {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        int testcases = Integer.parseInt(bufferedReader.readLine());

        for (int i = 0; i < testcases; i++) {
            int num = Integer.parseInt(bufferedReader.readLine());
            findPosition(fillMatrix(num), num);
        }
    }

    public static List<List<Integer>> fillMatrix(int num) {
        List<List<Integer>> matrix = new ArrayList<>();
        double rowsRequired; double columnsRequired;
        columnsRequired = rowsRequired = Math.ceil(Math.sqrt(num)); // next bigger positive integer to square root

        if (num < 1)
            throw new RuntimeException("Invalid Input");

        // initialize matrix of correct size with zeros
        for (int i = 0; i < rowsRequired; i++) {
            matrix.add(new ArrayList<>());
            for (int k = 0; k < columnsRequired; k++) {
                matrix.get(i).add(0);
            }
        }
        // fill matrix with correct values according to algorithm
        matrix.get(0).set(0, 1);
        int rowCounter = 0; int columnCounter = 1; int j = 2;

        while (j-1 < num) {
            while (matrix.get(rowCounter).get(columnCounter-1) != 0) {
                matrix.get(rowCounter).set(columnCounter, j);
                rowCounter++;
                j++;
            }
            for (int m = columnCounter; m >= 0; m--) {
                matrix.get(rowCounter).set(m, j);
                j++;
            }
            columnCounter++;
            rowCounter = 0;
        }

        // SHOW MATRIX
        /*for (List<Integer> row : matrix) {
            for (int numb : row) {
                System.out.print(numb + " ");
            }
            System.out.println();
        }*/
    return matrix;}

    public static void findPosition(List<List<Integer>> matrix, int num) {
        boolean contained = false; int rowIndex = 1; int columnIndex = 1;

        for (int i = 0; i < matrix.size(); i++) {
            List<Integer> row = matrix.get(i);
            for (int j = 0; j < row.size(); j++) {
                if (row.get(j) == num) {
                    contained = true;
                    rowIndex = i + 1; // + 1 just for mathematical 1-based indices
                    columnIndex = j + 1;
                    break;
                }
            }
        }

        if (!contained)
            throw new RuntimeException("Number not contained in matrix");

        System.out.println(rowIndex + " " + columnIndex);
    }
}

