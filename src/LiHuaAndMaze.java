import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class LiHuaAndMaze {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        int testcases = Integer.parseInt(bufferedReader.readLine());
        for (int i = 0; i < testcases; i++) {
            String [] nums = bufferedReader.readLine().split(" ");
            int rows = Integer.parseInt(nums[0]);
            int cols = Integer.parseInt(nums[1]);

            String [] coordinates = bufferedReader.readLine().split(" ");
            int startRow = Integer.parseInt(coordinates[0]);
            int startCol = Integer.parseInt(coordinates[1]);
            int endRow = Integer.parseInt(coordinates[2]);
            int endCol = Integer.parseInt(coordinates[3]);

            solve(rows, cols, startRow, startCol, endRow, endCol);
        }
    }

    public static void solve(int rows, int cols, int startRow, int startCol, int endRow, int endCol) {
        if (startRow == 1 && startCol == 1 || startRow == rows && startCol == cols ||
                startRow == 1 && startCol == cols || startRow == rows && startCol == 1 ||
                endRow == 1 && endCol == 1 || endRow == rows && endCol == cols ||
                endRow == 1 && endCol == cols || endRow == rows && endCol == 1) {
                System.out.println("2");
                return;
        }

        else if (startRow == 1 || startRow == rows || startCol == 1 || startCol == cols ||
                endRow == 1 || endRow == rows || endCol == 1 || endCol == cols) {
                System.out.println("3");
                return;
        }

        else {
            System.out.println("4");
            return;
        }
    }
}
