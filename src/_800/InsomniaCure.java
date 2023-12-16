import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;

public class InsomniaCure {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        int k = Integer.parseInt(bufferedReader.readLine());
        int l = Integer.parseInt(bufferedReader.readLine());
        int m = Integer.parseInt(bufferedReader.readLine());
        int n = Integer.parseInt(bufferedReader.readLine());
        int d = Integer.parseInt(bufferedReader.readLine());

        System.out.println(damagedDragons(k, l, m, n, d));
    }

    public static int damagedDragons(int k, int l, int m, int n, int d) {
        List<Integer> positions = new ArrayList<>();
        int [] intArray = new int []{k , l, m, n}; int i = 1;

        for (int each: intArray) {
            while (each * i <= d) {
                positions.add(each * i);
                i++;
            }
            i = 1;
        }

    return new HashSet<>(positions).size();}}