import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Too_Long_Words {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        int testcases = Integer.parseInt(bufferedReader.readLine());
        String [] words = new String[testcases];
        String [] shortened = new String[testcases];
        for (int i = 0; i < testcases; i++) {
            words[i] = bufferedReader.readLine();
            if (words[i].length() > 10)
                shortened[i] = shorten(words[i]);
            else shortened[i] = words[i];
        }
        bufferedReader.close();
        for (String word: shortened) {
            System.out.println(word);
        }
    }

    public static String shorten(String word) {
        int middle_sum = 0;
        char last_letter = word.charAt(word.length()-1);
        for (int i = 1; i < word.length() - 1; i++) {
            middle_sum++;
        }
        return word.charAt(0) + String.valueOf(middle_sum) + last_letter;
    }
}
