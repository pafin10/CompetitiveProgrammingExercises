import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Arrays;

public class DisplayTheNumber {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        int testcases = Integer.parseInt(bufferedReader.readLine());
        for (int i = 0; i < testcases; i++) {
            int n = Integer.parseInt(bufferedReader.readLine());
            System.out.println(computeGreatestInteger(n));
        }
    }

    public static BigInteger computeGreatestInteger(int n) {
        StringBuilder stringBuilder = new StringBuilder();
        int available_segments = n;
        if (n % 2 == 0) {
            for (int i = 0; i < n / 2; i++) {
                stringBuilder.append(1);
                available_segments -= 2;
            }

        } else {
            stringBuilder.append(7);
            available_segments -= 3;
            if (available_segments > 1) {
                for (int i = 1; i < n / 2; i++) {
                    stringBuilder.append(1);
                    available_segments -= 2;
                }
            }
        }

        if (available_segments > 0) {
            int i = 0; // number is bigger, other strategy necessary
            while (available_segments >= 4) { //difference #segments between 1 and 9
                stringBuilder.insert(i, 9);
                available_segments -= 4;
                i++;
            }
            while (available_segments > 0) {
                stringBuilder.insert(i, 7);
                available_segments --; i++;
            }
        }

        return new BigInteger(stringBuilder.toString());
    }
}
