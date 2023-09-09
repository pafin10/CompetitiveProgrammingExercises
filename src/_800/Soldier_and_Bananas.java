import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Soldier_and_Bananas {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        String[] line = bufferedReader.readLine().split(" ");
        int banana_cost = Integer.parseInt(line[0]); int budget = Integer.parseInt(line[1]); int desired_bananas = Integer.parseInt(line[2]);
        System.out.println(toBorrow(banana_cost, budget, desired_bananas));
    }

    public static int toBorrow(int cost, int budget, int desired) {
        int totalCost = 0;
        for (int i = 1; i <= desired; i++) {
            totalCost += i*cost;
        }
        if (totalCost - budget > 0)
            return totalCost-budget;
        else
            return 0;
    }
}
