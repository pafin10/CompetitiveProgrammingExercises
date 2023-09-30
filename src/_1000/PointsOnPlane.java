package _1000;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;

import static java.lang.Math.sqrt;

public class PointsOnPlane {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        int testcases = Integer.parseInt(bufferedReader.readLine());
        for (int i = 0; i < testcases; i++) {
            BigInteger chips = new BigInteger(bufferedReader.readLine());
            solve(chips);
        }
    }

    public static void solve(BigInteger chips) {
        BigInteger sqrt = chips.sqrt();

        if (chips.equals(BigInteger.ONE)) {
            System.out.println(0);
            return;
        }

        if (sqrt.pow(2).equals(chips)) {
            System.out.println(sqrt.subtract(BigInteger.ONE));
            return;
        }

        System.out.println(chips.sqrt());
    }
}
