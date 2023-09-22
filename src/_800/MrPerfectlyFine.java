package _800;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class MrPerfectlyFine {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        int testcases = Integer.parseInt(bufferedReader.readLine());
        for (int i = 0; i< testcases; i++) {
            int numBooks = Integer.parseInt(bufferedReader.readLine());
            int [] mins = new int[numBooks];
            String [] skills = new String[numBooks];
            for (int j = 0; j < numBooks; j++) {
                String [] nums = bufferedReader.readLine().split(" ");
                mins[j] = Integer.parseInt(nums[0]);
                skills[j] = nums[1];
            }
            solve(mins, skills);
        }
    }

    public static void solve(int [] mins, String [] skills) {
        boolean first = false; boolean second = false;
        List<Integer> potentialsOne = new ArrayList<>();
        List<Integer> potentialsTwo = new ArrayList<>();
        List<Integer> potentialsBoth = new ArrayList<>();
        List<Integer> positions = new ArrayList<>();
        int min = Integer.MAX_VALUE;
        int minOne = Integer.MAX_VALUE; int minTwo = Integer.MAX_VALUE;

        for (int i = 0; i < mins.length; i++) {
            potentialsBoth.clear();
            if(Integer.parseInt(skills[i].split("")[0]) == 1) {
                potentialsOne.add(mins[i]);
                potentialsBoth.add(mins[i]);
                first = true;
            }

            if (Integer.parseInt(skills[i].split("")[1]) == 1) {
                potentialsTwo.add(mins[i]);
                potentialsBoth.add(mins[i]);
                second = true;
            }
            if (potentialsBoth.size() == 2)
                positions.add(i);
        }

        if (!(first && second)) {
            System.out.println(-1);
            return;
        }

        if (positions.size() == 1)
            min = mins[positions.get(0)];

        for (int j = 0; j < positions.size(); j++) {
            if (mins[positions.get(j)] < min)
                min = mins[positions.get(j)];
        }

        for (int j = 0; j < potentialsOne.size(); j++) {
            if (potentialsOne.get(j) < minOne) {
                minOne = potentialsOne.get(j);
            }
        }

        for (int j = 0; j < potentialsTwo.size(); j++) {
            if (potentialsTwo.get(j) < minTwo) {
                minTwo = potentialsTwo.get(j);
            }
        }

        if (minOne + minTwo < min)
            System.out.println(minOne + minTwo);
        else
            System.out.println(min);
    }
}
