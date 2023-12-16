import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
public class Stones {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        int stones = Integer.parseInt(bufferedReader.readLine());
        String sequence = bufferedReader.readLine();
        System.out.println(takeOut(sequence));
    }

    public static int takeOut(String seq) {
        int delete = 0;
        for (int i = 0; i+1 < seq.length(); i++) {
            if (seq.charAt(i) == seq.charAt(i+1))
                delete +=1;
        }
        return delete;}
}
