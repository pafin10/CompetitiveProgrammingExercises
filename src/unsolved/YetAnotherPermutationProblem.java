package unsolved;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;

public class YetAnotherPermutationProblem {

    // WHAT CAN I FURTHER OPTIMIZE??
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        int testcases = Integer.parseInt(bufferedReader.readLine());
        for (int i = 0; i < testcases; i++) {
            int n = Integer.parseInt(bufferedReader.readLine());
            solve(n);
        }
    }

    public static void solve(int n) {
        List<Integer> arrList = new ArrayList<>();
        int start;
        HashSet<Integer> notUsed = new HashSet<>(n);
        StringBuilder stringBuilder = new StringBuilder();

        for (int i = 1; i < n; i++) {
            notUsed.add(i);
        }

        if (n%2 == 0)
            start = n;
        else
            start = n-1;

        for (int i = start; i > 0; i -= 2) {
            int tmp = i; int last = 2*i;
            while (tmp != 1 && 2 * tmp == last) {
                if (!arrList.contains(tmp)) {
                    arrList.add(tmp);
                }
                last = tmp;
                tmp /= 2;
            }
        }

        arrList.forEach(notUsed::remove);
        arrList.addAll(notUsed);

        if (n % 2 == 1)
            arrList.add(n);

        for (int elem: arrList) {
            stringBuilder.append(elem).append(" ");
        }
        System.out.println(stringBuilder);
    }
}
