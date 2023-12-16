package _900;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class NumberOfApartments {

    // THINK ABOUT IT
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        int testcases = Integer.parseInt(bufferedReader.readLine());
        for (int i = 0; i < testcases; i++) {
            int numWindows = Integer.parseInt(bufferedReader.readLine()); // is even
            calculateBuildings(numWindows);
        }
    }

    public static void calculateBuildings(int numWindows) {
        int sevenRooms = 0;
        int threeRooms = 0;
        int fiveRooms = 0;
        boolean found = false;

        if (numWindows == 1 || numWindows == 2 || numWindows == 4) {
            System.out.println(-1); return;
        }

        for (int i = 1; i < 1001 / 3; i++) {
            for (int j = 1; j < 1001 / 5; j++) {
                for (int k = 1; k < 1001 / 7; k++) {

                    if (numWindows % 7 == 0 || numWindows % 7 == 3 * i || numWindows % 7 == 5 * i) {
                        sevenRooms = numWindows / 7;
                        numWindows -= sevenRooms * 7;
                    }
                    if (numWindows % 5 == 0 || numWindows % 5 == 3 * i) {
                        fiveRooms = numWindows / 5;
                        numWindows -= fiveRooms * 5;
                    }
                    if (numWindows % 3 == 0) {
                        threeRooms = numWindows / 3;
                        numWindows -= threeRooms * 3;
                    }
                    if (numWindows == 3 * i + 5 * j) {
                        while (numWindows % 3 != 0) {
                            numWindows -= 5;
                            fiveRooms++;
                        }
                        while (numWindows > 0) {
                            numWindows -= 3;
                            threeRooms++;
                        }
                    }
                    if (numWindows == 3 * i + 7 * k) {
                        while (numWindows % 3 != 0) {
                            numWindows -= 7;
                            sevenRooms++;
                        }
                        while (numWindows > 0) {
                            numWindows -= 3;
                            threeRooms++;
                        }
                    }
                    if (numWindows == 5 * j + 7 * k) {
                        while (numWindows % 7 != 0) {
                            numWindows -= 7;
                            sevenRooms++;
                        }
                        while (numWindows > 0) {
                            numWindows -= 5;
                            fiveRooms++;
                        }
                    }

                    if (numWindows == 3 * i + 5 * j + 7 * k) {
                        while (numWindows % 5 != 0) {
                            numWindows -= 7;
                            sevenRooms++;
                        }
                        while (numWindows % 3 != 0) {
                            numWindows -= 5;
                            fiveRooms++;
                        }
                        while (numWindows > 0) {
                            numWindows -= 3;
                            threeRooms++;
                        }
                    }

                    if (numWindows == 0) {
                        found = true;
                        System.out.println(threeRooms + " " + fiveRooms + " " + sevenRooms);
                        break;
                    }
                }
                if (found)
                    break;
            }
            if (found)
                break;
        }
        if (!found)
            System.out.println(-1);
    }
}


