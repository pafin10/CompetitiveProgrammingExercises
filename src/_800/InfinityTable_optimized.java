import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class InfinityTable_optimized {
        public static void main(String[] args) throws IOException {
            BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
            int testcases = Integer.parseInt(bufferedReader.readLine());

            for (int i = 0; i < testcases; i++) {
                int num = Integer.parseInt(bufferedReader.readLine());
                int[] position = findPosition(num);
                System.out.println(position[0] + " " + position[1]);
            }
        }

        public static int[] findPosition(int num) {
            if (num < 1)
                throw new RuntimeException("Invalid Input");

            int layer = (int) Math.ceil(Math.sqrt(num));
            int layerStart = (layer - 1) * (layer - 1) + 1;
            int layerEnd = layer * layer;

            int rowIndex, colIndex;


            if (num <= layerStart + (layer - 1)) {
                colIndex = layer;
                rowIndex = num - layerStart + 1;
            } else {
                rowIndex = layer;
                colIndex = layerEnd - num + 1;
            }

            return new int[]{rowIndex, colIndex};
        }
    }






