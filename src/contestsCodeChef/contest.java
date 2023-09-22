package contestsCodeChef;/* package codechef; // don't place package name! */

import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Lockpick
{
    public static void main (String[] args) throws java.lang.Exception
    {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        int testcases = Integer.parseInt(bufferedReader.readLine());
        for (int i = 0; i < testcases; i++) {
            String [] nums = bufferedReader.readLine().split(" ");
            int N = Integer.parseInt(nums[0]);
            int M = Integer.parseInt(nums[1]);
            String S = bufferedReader.readLine();
            String K = bufferedReader.readLine();
            solve(N, M, S, K);
        }
    }

    public static void solve(int lengthString, int lengthCode, String str, String code) {
        int [] intArr = new int[lengthString - lengthCode + 1]; int minMoves = lengthCode*5;
        for (int i = 0; i < lengthString - lengthCode + 1; i++) {
            if (str.substring(i, i+ lengthCode).equals(code)) {
                System.out.println(0);
                return;
            }
            else {
                int diff = 0; int diffSum = 0;
                for (int j = 0; j < lengthCode; j++) {
                    diff = 0;
                    if (str.charAt(i+j) != code.charAt(j)) {
                        diff += Math.abs(str.charAt(i+j) - code.charAt(j));
                        if (diff > 5) {
                            int first = Character.getNumericValue(str.charAt(i+j));
                            int second = Character.getNumericValue(code.charAt(j));
                            int smaller = Math.min(first, second);
                            int bigger = Math.max(first, second);
                            diff = Math.abs(Integer.parseInt("1" + smaller) - bigger);
                        }
                    }
                    diffSum += diff;
                }
                intArr[i] = diffSum;
            }
        }

        for (int entr: intArr) {
            if (entr < minMoves)
                minMoves = entr;
        }
        System.out.println(minMoves);
    }
}