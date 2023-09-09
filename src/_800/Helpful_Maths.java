import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Helpful_Maths {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        String line;
        StringBuilder sb = new StringBuilder();
        while (!((line = bufferedReader.readLine()) == null) && !(line.isEmpty())) {
            sb.append(line);
        }
        bufferedReader.close();
        String addition = sb.toString();
        String [] numbers = addition.split("\\+");
        Arrays.sort(numbers);
        System.out.println(String.join("+", numbers));
    }}