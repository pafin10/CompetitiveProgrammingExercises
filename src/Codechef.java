/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef {
    public static void main(String[] args) throws java.lang.Exception {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        int testcases = Integer.parseInt(bufferedReader.readLine());
        for (int i = 0; i < testcases; i++) {
            String[] nums = bufferedReader.readLine().split(" ");
            int numEnem = Integer.parseInt(nums[0]);
            int initStrength = Integer.parseInt(nums[1]);
            String[] strengths = bufferedReader.readLine().split(" ");
            int[] intArr = new int[numEnem];
            for (int j = 0; j < numEnem; j++) {
                intArr[j] = Integer.parseInt(strengths[j]);
            }
            solve(numEnem, initStrength, intArr);
        }
    }

    public static void solve(int numEnem, int initStrength, int [] enemyStrengths) {
        int resistance = 0; int strength; int count = 0;
        while (true) {
            count = 0;
            strength = initStrength;
            for (int i = 0; i < numEnem; i++) {
                if (resistance >= enemyStrengths[i]) {
                    count++;
                    continue;
                }
                strength -= enemyStrengths[i];
                if (strength <= 0) {
                    resistance++;
                    break;
                }
                count++;
            }
            if (count == numEnem) {
                System.out.println(resistance);
                break;
            }
        }
    }
}
