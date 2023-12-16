package contestsCodeChef;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BitPlay {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int testcases = Integer.parseInt(br.readLine());
        for (int i = 0; i < testcases; i++) {
            int N = Integer.parseInt(br.readLine());
            String s = br.readLine();
            solve(N, s);
        }
    }

    public static void solve(int N, String s) {
        // there are 3 operators that can be combined in 3^2 ways, so 9 options for each pair of numbers
        long ans = 1; int mod = 1000000007;
        for (int i = 2; i < N; i+=2) {
            if (s.charAt(i) == '1') {
                switch("" + s.charAt(i-1)+s.charAt(i-2)) {
                    case "01", "10":
                        ans = ans*2 % mod;
                        break;
                    case "11":
                        ans = ans*2 % mod;
                        break;
                    case "00":
                        System.out.println("0");
                        return;
                }
            }
            else if ((""+ s.charAt(i-1) + s.charAt(i-2)).equals("00")){
                ans = ans*3%mod;
            }

        }
        System.out.println(ans);
    }
}
