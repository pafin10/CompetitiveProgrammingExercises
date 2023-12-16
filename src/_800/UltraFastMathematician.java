import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class UltraFastMathematician {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        String first = bufferedReader.readLine();
        String second = bufferedReader.readLine();
        StringBuilder stringBuilder = new StringBuilder();
        for (int i = 0; i < first.length(); i++) {
            if (first.charAt(i) == second.charAt(i))
                stringBuilder.append("0");
            else
                stringBuilder.append("1");
        }
        System.out.println(stringBuilder.toString());
    }
}
