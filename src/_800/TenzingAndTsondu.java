package _800;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class TenzingAndTsondu {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        int testcases = Integer.parseInt(bufferedReader.readLine());
        for (int i = 0; i < testcases; i++) {
            String [] nums = bufferedReader.readLine().split(" ");
            int monTsondu = Integer.parseInt(nums[0]);
            int monTenzing = Integer.parseInt(nums[1]);
            String [] tsondu = bufferedReader.readLine().split(" ");
            String [] tenzing = bufferedReader.readLine().split(" ");
            int [] tsonduArr = new int[monTsondu];
            int [] tenzingArr = new int[monTenzing];
            int tsonduSum = 0; int tenzingSum = 0;
            for (int j = 0; j < monTsondu; j++) {
                tsonduArr[j] = Integer.parseInt(tsondu[j]);
            }
            for (int j = 0; j < monTenzing; j++) {
                tenzingArr[j] = Integer.parseInt(tenzing[j]);
            }

            solve(tsonduArr, tenzingArr);
        }
    }

    public static void solve(int [] tsonduArr, int [] tenzingArr) {
        List<Integer> tsondu = new ArrayList<>();
        List<Integer> tenzing = new ArrayList<>();
        int count = 0;

        for (int i = 0; i < tsonduArr.length; i++) {
            tsondu.add(tsonduArr[i]);
        }

        for (int j = 0; j < tenzingArr.length; j++) {
            tenzing.add(tenzingArr[j]);
        }

        tsondu.sort(Collections.reverseOrder());
        tenzing.sort(Collections.reverseOrder());

        while (!tsondu.isEmpty() && !tenzing.isEmpty()) {
            int tenzingHere = tenzing.get(count);
            int tmp = tenzingHere;
            tenzingHere -= tsondu.get(count);
            if (tenzingHere <= 0)
                tenzing.remove(count);
            else
                tenzing.set(count, tenzingHere);

            int tsonduHere = tsondu.get(count);
            tsonduHere -= tmp;
            if (tsonduHere <= 0)
                tsondu.remove(count);
            else
                tsondu.set(count, tsonduHere);
        }

        if (tsondu.isEmpty() && tenzing.isEmpty()) {
            System.out.println("Draw");
        }

        else if (tenzing.isEmpty()) {
            System.out.println("Tsondu");
        }

        else {
            System.out.println("Tenzing");
        }
    }
}
