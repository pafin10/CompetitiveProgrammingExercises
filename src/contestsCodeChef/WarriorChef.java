package contestsCodeChef;/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class WarriorChef
{
    public static void main (String[] args) throws java.lang.Exception
    {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bufferedReader.readLine());
        for (int i = 0; i < t; i++) {
            String [] nums = bufferedReader.readLine().split(" ");
            int numEnem = Integer.parseInt(nums[0]);
            int strength = Integer.parseInt(nums[1]);
            int [] arr = new int[numEnem];
            String [] nums2 = bufferedReader.readLine().split(" ");
            for (int j = 0; j < numEnem; j++) {
                arr[j] = Integer.parseInt(nums2[j]);
            }
            solve(numEnem, strength, arr);
        }
    }

    public static void solve(int numEnem, int initStrength, int [] enemyStrengths) {
        int sum = 0;
        List<Integer> sorted = new ArrayList<>();

        for (int i = 0; i < numEnem; i++) {
            sorted.add(enemyStrengths[i]);
        }

        Collections.sort(sorted);
        int j = sorted.size() - 1;
        while (initStrength > sum && j >= 0) {
            sum += sorted.get(j);
            j--;
        }

        if (sum < initStrength) {
            System.out.println(0);
            return;
        }

        System.out.println(sorted.get(j + 1));
    }
}

