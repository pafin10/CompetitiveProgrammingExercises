import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class ComparisonString {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        int testCases = Integer.parseInt(bufferedReader.readLine());
        String [] sequences = new String[testCases];
        for (int i = 0; i < testCases; i++) {
            bufferedReader.readLine();
            sequences[i] = bufferedReader.readLine();
        }
        minCost(sequences);
    }

    // Whats the rule?
    public static void minCost(String [] sequences) {
        int [] costs = new int[sequences.length];
        for (int i = 0; i < sequences.length; i++) {
            int max = 1;
            int cost = 1;
            String seq = sequences[i];

            for (int j = 0; j < seq.length() - 1; j++) {
                if (seq.charAt(j) == seq.charAt(j+1))
                    cost++;
                else
                    cost = 1;
                if (cost + 1 > max)
                    max = cost + 1;
            }
            costs[i] = max >= 2 ? max : 2;
        }
        for (int cost: costs) {
            System.out.println(cost);
        }
    }
}
