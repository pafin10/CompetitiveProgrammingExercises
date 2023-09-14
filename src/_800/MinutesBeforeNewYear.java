import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class MinutesBeforeNewYear {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        int testcases = Integer.parseInt(bufferedReader.readLine());
        for (int i = 0; i < testcases; i++) {
            String[] nk = bufferedReader.readLine().split(" "); // is even
            int h = Integer.parseInt(nk[0]);
            int m = Integer.parseInt(nk[1]);
            timeToNewYear(h, m);
        }
    }

    public static void timeToNewYear(int h, int m) {
        int hoursLeft = 23 - h;
        int minutesToFullHour = 60 - m;
        System.out.println(hoursLeft * 60 + minutesToFullHour);
    }
}
