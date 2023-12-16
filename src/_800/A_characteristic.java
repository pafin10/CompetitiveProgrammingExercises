package _800;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class A_characteristic {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        int testcases = Integer.parseInt(bufferedReader.readLine());
        for (int i = 0; i < testcases; i++) {
            String [] arr = bufferedReader.readLine().split(" ");
            int n = Integer.parseInt(arr[0]);
            int k = Integer.parseInt(arr[1]);
            solve(n, k);
        }
    }

    public static void solve(int n, int k) {
        int [] intArr = new int[n]; boolean found = false;
        int possible = (n * (n-1)) / 2;
        StringBuilder stringBuilder = new StringBuilder();

        Arrays.fill(intArr, 1);
        if (possible == k) {
            System.out.println("YES");
            for (int elem: intArr) {
                stringBuilder.append(elem).append(" ");
            }
            System.out.println(stringBuilder);
        return;
        }

        for (int i = 0; i < n/2; i++) {
            intArr[i] = -1;
            possible -= ((n - (i+1)) - i);
            if (possible == k) {
                found = true;
                System.out.println("YES");
                for (int value : intArr) {
                    stringBuilder.append(value).append(" ");
                }
                System.out.println(stringBuilder);
                break;
            }
        }
        if (!found)
            System.out.println("NO");
    }
}

