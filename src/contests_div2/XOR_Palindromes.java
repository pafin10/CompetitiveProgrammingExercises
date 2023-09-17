package contests_div2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class XOR_Palindromes {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        int testcases = Integer.parseInt(bufferedReader.readLine());
        for (int i = 0; i < testcases; i++) {
            int length = Integer.parseInt(bufferedReader.readLine());
            solve(length, bufferedReader.readLine());
        }
    }

    public static void solve(int length, String s) {
        int sym = 0; int mid = 0; int asym = 0;
        char [] sArr = s.toCharArray();
        String [] ans = new String[length + 1];

        for (int i = 0; i < length + 1; i++) {
            ans[i] = "0";
        }

        for (int i = 0; i < length - i - 1; i++) {
            if (sArr[i] == sArr[length - i - 1])
                sym++;
            else
                asym++;
        }

        if (length % 2 == 1)
            mid = 1;

        for (int i = 0; i <= mid; ++i) {
            for (int j = 0; j <= sym; ++j) {
                ans[i + asym + 2 * j] = "1";
            }
        }

        StringBuilder stringBuilder = new StringBuilder();
        for (int i = 0; i < length + 1; i++) {
            stringBuilder.append(ans[i]);
        }

        System.out.println(stringBuilder);
    }
}
