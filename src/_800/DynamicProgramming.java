package _800;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class DynamicProgramming {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        int testcases = Integer.parseInt(bufferedReader.readLine());
        for (int i = 0; i < testcases; i++) {
            int arrayLength = Integer.parseInt(bufferedReader.readLine());
            String[] strArray = new String[arrayLength];
            int[] intArray = new int[strArray.length];
            strArray = bufferedReader.readLine().split(" ");
            for (int j = 0; j < arrayLength; j++) {
                intArray[j] = Integer.parseInt(strArray[j]);
            }
            System.out.println(operationsToBecomeGood(intArray));
        }
    }

    public static int operationsToBecomeGood(int[] intArray) {
        int sum = 0; int choice;
        int [] allCounts = new int[intArray.length];
        int min = Integer.MAX_VALUE;

        for (int k : intArray) {
            sum += k;
        }

        if (sum % 2 == 0)
            return 0;

        for (int i = 0; i < intArray.length; i++) {
            int init = sum;
            int count = 0;
            choice = intArray[i];

            while (sum % 2 != 0) {
                sum -= choice;
                choice /= 2;
                sum += choice;
                count++;
            }
            allCounts[i] = count;
            sum = init;
        }
        for (int num: allCounts) {
            if (num < min)
                min = num;
        }
    return min;}
}
