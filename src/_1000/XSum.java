package _1000;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class XSum {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        int testcases = Integer.parseInt(bufferedReader.readLine());
        for (int i = 0; i < testcases; i++) {
            String [] nums = bufferedReader.readLine().split(" ");
            int n = Integer.parseInt(nums[0]);
            int m = Integer.parseInt(nums[1]);
            int [][] grid = new int[n][m];
            for (int j = 0; j < n; j++) {
                String [] row = bufferedReader.readLine().split(" ");
                for (int k = 0; k < m; k++) {
                    grid[j][k] = Integer.parseInt(row[k]);
                }
            }
            solve(n, m, grid);
        }
    }

    public static void solve(int rows, int cols, int[][] grid) {
        int sum = 0;
        List<Integer> sums = new ArrayList<>();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                sum += grid[i][j];
                int leftUp = Math.min(i, j);
                int rightUp = Math.min(i, cols - j - 1);
                int leftDown = Math.min(rows - i - 1, j);
                int rightDown = Math.min(rows - i - 1, cols - j - 1);
                int k = 1;

                while (true) {
                    boolean ranThis = false;
                    if (k <= leftUp) {
                        sum += grid[i-k][j-k];
                        ranThis = true;
                    }
                    if (k <= rightUp) {
                        sum += grid[i-k][j+k];
                        ranThis = true;
                    }
                    if (k <= leftDown) {
                        sum += grid[i+k][j-k];
                        ranThis = true;
                    }
                    if (k <= rightDown) {
                        sum += grid[i+k][j+k];
                        ranThis = true;
                    }
                    if (!ranThis) {
                        break;
                    }
                    k++;
                }

                sums.add(sum);
                sum = 0;
            }
        }

        int max = sums.get(0);
        for (Integer integer : sums) {
            if (max < integer)
                max = integer;
        }

        System.out.println(max);
    }
}

