package _800;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;

public class BlackboardList {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        int testcases = Integer.parseInt(bufferedReader.readLine());
        for (int i = 0; i < testcases; i++) {
            int length = Integer.parseInt(bufferedReader.readLine());
            String [] nums = bufferedReader.readLine().split(" ");
            int [] intArr = new int[length];
            for (int j = 0; j < length; j++) {
                intArr[j] = Integer.parseInt(nums[j]);
            }
            solve(length, intArr);
        }
    }

    public static void solve(int length, int [] intArr) {
        List<Integer> arrList = new ArrayList<>();
        HashSet<Integer> diffs = new HashSet<>(length);
        for (int elem: intArr) {
            arrList.add(elem);
        }
        for (int i = 0; i < length -1; i++) {
            if (intArr[i] < 0) {
                System.out.println(intArr[i]);
                return;
            }
        }

        for (int i = 0; i < length -1; i++) {
            for (int j = 1; j < length; j++) {
                int diffOne = Math.abs(intArr[i] - intArr[j]);
                int diffTwo = Math.abs(intArr[j] - intArr[i]);
                diffs.add(diffOne); diffs.add(diffTwo);
            }
        }

        if (diffs.size() == 1) {
            System.out.println(intArr[0]);
            return;
        }

        for (int elem: arrList) {
            if (!diffs.contains(elem)) {
                System.out.println(elem);
                return;
            }
        }

        // ELSE: MAX CAUSE NO DIFFERENCE CAN BE LAGER THAN MAX
        int max = intArr[0];
        for (int i = 0; i < length - 1; i++) {
            if (max < intArr[i+1]) {
                max = intArr[i+1];
            }
        }
        System.out.println(max);
    }
}

