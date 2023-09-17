import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

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
        List<int []> pairs = new ArrayList<>();
        List<int []> foundPairs = new ArrayList<>();
        Set<Integer> used = new HashSet<>();


        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                if ((a + k) * b % 4 == 0)
                    pairs.add(new int[]{a, b});
            }
        }

        for (int i = 0; i < pairs.size(); i++) {
            String [] pair = Arrays.toString(pairs.get(i)).split(", ");
            int first = Integer.parseInt(pair[0].substring(1));
            int second = Integer.parseInt(pair[1].substring(0, pair[1].length()-1));
            if (!used.contains(first) && !used.contains(second)) {
                used.add(first); used.add(second);
                foundPairs.add(pairs.get(i));
            }
        }

        if (foundPairs.size() != n/2)
            System.out.println("NO");

        System.out.println("YES");
        for (int[] pair : pairs) {
            System.out.println(pair[0] + " " + pair[1]);
        }
    }
}







