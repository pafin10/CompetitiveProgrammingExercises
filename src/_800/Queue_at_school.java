import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Queue_at_school {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        String lineOne = bufferedReader.readLine();
        String arrangement = bufferedReader.readLine();
        String[] nums = lineOne.split(" ");
        int numChildren = Integer.parseInt(nums[0]);
        int time = Integer.parseInt(nums[1]);
        System.out.println(rearrange(arrangement, numChildren, time));
    }

    public static String rearrange(String arrangement, int children, int time) {
        char [] charArray = arrangement.toCharArray();
        for (int i = 0; i < time; i++) {
            for (int j = 0; j +1 < children; j++) {
                if (charArray[j] == 'B' && charArray[j+1] == 'G') {
                    char tmp = charArray[j];
                    charArray[j] = charArray[j+1];
                    charArray[j+1] = tmp;
                    j++;
                }
            }
        }
        return new String(charArray);
    }

    public static String swap(String s, int position1, int position2) {
        char[] charArray = s.toCharArray();


        return new String(charArray);
    }
}