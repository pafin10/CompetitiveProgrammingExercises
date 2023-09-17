package _800;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Matching {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        int testcases = Integer.parseInt(bufferedReader.readLine());
        for (int i = 0; i < testcases; i++) {
            String template = bufferedReader.readLine();
            System.out.println(computeMatches(template));
        }
    }

    public static int computeMatches(String template) {
        int options = 1;
        if (template.charAt(0) == '?')
            options = 9;
        else if (template.charAt(0) == '0')
            return 0;
        if (template.length() == 1 && template.charAt(0) != '?')
            return 1;


        for (int i = 1; i < template.length(); i++) {
            if (template.charAt(i) == '?')
                options *= 10;
        }
    return options;}
}
