import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public class AmusingJoke {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        String first = bufferedReader.readLine();
        String second = bufferedReader.readLine();
        String shuffled = bufferedReader.readLine();
        System.out.println(permutation(first, second, shuffled));
    }

    public static String permutation(String first, String second, String shuffled) {
        HashMap<Character, Integer> letter_count = new HashMap<>();
        HashMap<Character, Integer> shuffle_count = new HashMap<>();

        for (int i = 0; i < first.length(); i++) {
                char update = first.charAt(i);
                letter_count.put(update, letter_count.getOrDefault(update, 0) +1);
            }
        for (int j = 0; j < second.length(); j++) {
                char update = second.charAt(j);
                letter_count.put(update, letter_count.getOrDefault(update, 0) +1);
            }
        for (int k = 0; k < shuffled.length(); k++) {
            char update = shuffled.charAt(k);
            shuffle_count.put(update, shuffle_count.getOrDefault(update, 0) +1);
            }
        if (letter_count.equals(shuffle_count))
            return "YES";
        return "NO";
    }
}
