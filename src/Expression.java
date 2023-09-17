import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;

public class Expression {

    // TO BE CONTINUED; USE SWITCH
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        int a = Integer.parseInt(bufferedReader.readLine());
        int b = Integer.parseInt(bufferedReader.readLine());
        int c = Integer.parseInt(bufferedReader.readLine());
        maxValue(a, b, c);
    }

    public static void maxValue(int a, int b, int c) {
        HashSet<Character> operands = new HashSet<>(); int fresh = 0; int max = 0;
        operands.add('+'); operands.add('*');
        for (char operand:operands) {
            for (char operand1:operands) {
                fresh = a + operand + b + operand1 + c;
                max = Math.max(fresh, max);
            }
        }
        System.out.println(max);

    }
}
