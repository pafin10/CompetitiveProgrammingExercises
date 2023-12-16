import java.util.Scanner;

public class Dominos {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int M = scanner.nextInt();
        int N = scanner.nextInt();
        scanner.nextLine();
        System.out.println(calcDominos(M, N));
    }

    public static int calcDominos(int m, int n) {
        int area = m*n;
        int numberDominos = area / 2;
        return numberDominos;
    }
}
