package _900;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;

public class MisloveHasLostAnArray {

    // CONTINUE TOMORROW
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        String [] nums = bufferedReader.readLine().split(" ");
        int n = Integer.parseInt(nums[0]);
        int l = Integer.parseInt(nums[1]);
        int r = Integer.parseInt(nums[2]);
        computeMinMaxSumsOfElements(n, l, r);
    }

    public static void computeMinMaxSumsOfElements(int arrayLength, int minElements, int maxElements) {
        List<Integer> minList = new ArrayList<>();
        List<Integer> maxList = new ArrayList<>();
        int minSum = 0; int maxSum = 0;
        int spotsLeftMin = arrayLength - minElements;
        int spotsLeftMax = arrayLength - maxElements;

        // 1 is necessarily in array at least once

        // for any a_i != 1, there has to be an a_i / 2 in the array, so really, it just doubles up from 1
        // MINIMAL SUM
        for (int i = 0; i < arrayLength; i++) {
            if (minList.size() == minElements)
                minSum ++;
            else {
                minSum += Math.pow(2, i);
                minList.add((int) Math.pow(2, i));
            }
        }

        // MAXIMAL SUM
        int largest = 0;
        for (int i = 0; i < arrayLength; i++) {
            if (maxList.size() == maxElements)
                maxSum += maxList.get(maxList.size()-1);
            else {
                maxSum += Math.pow(2, i);
                maxList.add((int) Math.pow(2, i));
            }
        }

        System.out.println(minSum + " " + maxSum);

    }
}
