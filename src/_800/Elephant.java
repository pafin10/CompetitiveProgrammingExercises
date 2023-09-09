import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Elephant {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        int friend_house = Integer.parseInt(bufferedReader.readLine());
        System.out.println(steps(friend_house));
    }

    public static int steps(int friend_house) {
        if (friend_house < 5)
            return 1;
        else
            return friend_house % 5 == 0 ? friend_house/5 : friend_house/5 + 1;
    }
}
