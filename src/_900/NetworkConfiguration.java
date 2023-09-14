import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;

public class NetworkConfiguration {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        String [] nums = bufferedReader.readLine().split(" ");
        int computers = Integer.parseInt(nums[0]);
        int participants = Integer.parseInt(nums[1]);
        String [] speedsStr = bufferedReader.readLine().split(" ");
        int [] speeds = Arrays.stream(speedsStr)
                .mapToInt(Integer::parseInt)
                .toArray();
        computeMaxSpeed(computers, participants, speeds);
    }

    public static void computeMaxSpeed(int comp, int part, int [] speeds) {
        Arrays.sort(speeds);
        int [] reversedSpeeds = new int[speeds.length];
        for (int i = 0; i < comp; i++) {
            reversedSpeeds[i] = speeds[speeds.length - 1 - i];
        }
        int maxSpeed = reversedSpeeds[part - 1];
        System.out.println(maxSpeed);
    }
}
