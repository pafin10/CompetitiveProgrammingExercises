package _900;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class MathematicalCircus_naive {

    // TO BE CONTINUED; EFFICIENCY
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        int testcases = Integer.parseInt(bufferedReader.readLine());
        for (int i = 0; i < testcases; i++) {
            String[] nk = bufferedReader.readLine().split(" "); // is even
            int n = Integer.parseInt(nk[0]);
            int k = Integer.parseInt(nk[1]);
            checkPossibleSplit(n, k);
        }
    }

    public static void checkPossibleSplit(int n, int k) {
        // to check: (a+k) * b divisible by 4 for all integers element of (1, ..., n) where each integer is part of one pair (a, b) ?
        HashMap<Integer, List<Integer>> pairs = new HashMap<>();
        ArrayList<Integer> foundPairs = new ArrayList<>();


        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                if (a != b && (a + k) * b % 4 == 0) {
                    pairs.computeIfAbsent(a, key -> new ArrayList<>()).add(b);
                }
            }
        }

        for (Map.Entry<Integer, List<Integer>> pair : pairs.entrySet()) {
            int a = pair.getKey();
            if (foundPairs.contains(a))
                continue;
            List<Integer> bValues = pair.getValue();
            for (int b : bValues) {
                if (!foundPairs.contains(a) && !foundPairs.contains(b)) {
                    foundPairs.add(a);
                    foundPairs.add(b);
                }
            }
        }

        if (foundPairs.size() == n) {
            System.out.println("YES");
            for (int i = 0; i < foundPairs.size(); i += 2) {
                System.out.println(foundPairs.get(i) + " " + foundPairs.get(i + 1));
            }
        }
        else
            System.out.println("NO");
    }
}







