package _800;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static java.util.Arrays.sort;

public class ParitySort {
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
            solve(intArr);
        }
    }

    public static void solve(int[] arr) {
        List<Integer> evenList = new ArrayList<>();
        List<Integer> oddList = new ArrayList<>();
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] % 2 == 0)
                evenList.add(arr[i]);
            else
                oddList.add(arr[i]);
        }

        // IN PLACE SORTING
        Collections.sort(evenList);
        Collections.sort(oddList);

        int oddCount = 0; int evenCount = 0;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] % 2 == 0)
                arr[i] = evenList.get(evenCount++);
            else
                arr[i] = oddList.get(oddCount++);
        }

        int [] copy = Arrays.copyOf(arr, arr.length);
        sort(copy);

        if (Arrays.equals(copy, arr))
            System.out.println("YES");
        else
            System.out.println("NO");
    }
}
