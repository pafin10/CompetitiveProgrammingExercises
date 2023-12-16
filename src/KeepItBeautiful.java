import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

import static java.util.Collections.sort;

public class KeepItBeautiful {

    // SOLUTION WORKS, BUT TOO INEFFICIENT: OPTIMIZE
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        int testcases = Integer.parseInt(bufferedReader.readLine());
        for (int i = 0; i < testcases; i ++) {
            int q = Integer.parseInt(bufferedReader.readLine());
            String [] nums = bufferedReader.readLine().split(" ");
            int [] intArr = new int[q];
            for (int j = 0; j < q; j++) {
                intArr[j] = Integer.parseInt(nums[j]);
            }
            solve(q, intArr);
        }
    }

    public static void solve(int queries, int [] arr) {
        List<Integer> intList = new ArrayList<>();
        for (int i = 0; i < queries; i++) {
            intList.add(arr[i]);
        }
        List<Integer> beautiful = new ArrayList<>();
        List<Integer> outs = new ArrayList<>();
        beautiful.add(arr[0]); outs.add(1);
        boolean sorted = true;

        for (int i = 0; i < queries - 1; i++) {

            if (arr[i+1] >= beautiful.get(beautiful.size() - 1) && sorted) {
                beautiful.add(arr[i + 1]);
                outs.add(1);
            }

            else if (arr[i+1] < beautiful.get(0) && sorted) {
                beautiful.add(arr[i + 1]);
                outs.add(1);
                sorted = false;
            }

            else if (beautiful.get(0) >= arr[i+1]) {
                int size = beautiful.size();

                for (int j = 1; j <= size; j++) {
                    List<Integer> tmp = new ArrayList<>(new ArrayList<>(beautiful.subList(j, size)));
                    tmp.add(arr[i + 1]);
                    tmp.addAll(new ArrayList<>(beautiful.subList(0, j)));

                    List<Integer> copy = new ArrayList<>(tmp);
                    sort(copy);
                    if (copy.equals(tmp)) {
                        outs.add(1);
                        beautiful.add(arr[i + 1]);
                        sorted = false;
                        break;
                    }
                }
                if (size == beautiful.size()) {
                    outs.add(0);
                }
            }

            else {
                outs.add(0);
            }
        }
        //System.out.println(beautiful);
        for (int out: outs) {
            System.out.print(out);
        }
        System.out.println(" ");
    }
}
