import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class MathematicalCircus {

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
        Set<Integer> nums = new HashSet<>();
        HashMap<Integer, List<Integer>> pairs = new HashMap<>();
        HashMap<Integer, Integer> foundPairs = new HashMap<>();

        for (int i = 1; i <= n; i++) {
            nums.add(i);
        }

        for (int a : nums) {
            for (int b : nums) {
                if (a != b && (a + k) * b % 4 == 0) {
                    pairs.computeIfAbsent(a, key -> new ArrayList<>()).add(b);
                }
            }
        }

        boolean found = false;
        while (foundPairs.size() < pairs.size()) {
            for (Map.Entry<Integer, List<Integer>> pair : pairs.entrySet()) {
                int key = pair.getKey();
                for (Integer value: pair.getValue()) {
                    if (nums.contains(key) && nums.contains(value)) {
                        foundPairs.put(key, value);
                        nums.remove(key); nums.remove(value);
                    }
                }
            }
            if (nums.isEmpty()) {
                found = true;
                break;
            }
        }

        if (found) {
            System.out.println("YES");
            for (Map.Entry<Integer, Integer> pair: foundPairs.entrySet()) {
                System.out.println(pair.getKey() + " " + pair.getValue());
            }
        }

        else
            System.out.println("NO");
    }
}







