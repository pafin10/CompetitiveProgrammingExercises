import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Elections {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        int numStudents = Integer.parseInt(bufferedReader.readLine());
        String [] strOpponentArray = bufferedReader.readLine().split(" ");
        int [] opponentArray = new int[strOpponentArray.length];
        for (int i = 0; i < strOpponentArray.length; i++) {
            opponentArray[i] = Integer.parseInt(strOpponentArray[i]);
        }
        compute_k(numStudents, opponentArray);
    }

    public static void compute_k(int numStudents, int [] opponentArray) {
        int maxElement = opponentArray[0]; int opponentScore = 0; int awrukScore = 0;
        for (int i = 0; i < opponentArray.length; i++) {
            opponentScore += opponentArray[i];
            if (opponentArray[i] > maxElement)
                maxElement = opponentArray[i];
        }
        awrukScore = numStudents * maxElement - opponentScore;

        if (awrukScore > opponentScore)
            System.out.println(maxElement);
        else {
            int k = maxElement;
            while (awrukScore <= opponentScore) {
                k++;
                awrukScore = numStudents * k - opponentScore;
            }
            System.out.println(k);
        }

    }
}
