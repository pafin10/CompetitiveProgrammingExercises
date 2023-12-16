package contests_div3;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class VasilijeInCack {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        int testcases = Integer.parseInt(bufferedReader.readLine());

        for (int i = 0; i < testcases; i++) {
            String [] nums  = bufferedReader.readLine().split(" ");
            long n = Long.parseLong(nums[0]);
            long k = Long.parseLong(nums[1]);
            long x = Long.parseLong(nums[2]);
            solve(n, k, x);
        }
    }
    public static void solve(long max, long num, long sum) {
        if (num * (num + 1) / 2 <= sum && sum <= num * (max + max - num +1) / 2) {
            System.out.println("YES");
        }
        else {
            System.out.println("NO");
        }
    }
}

