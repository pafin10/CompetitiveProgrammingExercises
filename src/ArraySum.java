import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class ArraySum {

    // GO THROUGH FINAL LOOP AGAIN
        static class FastReader {
            BufferedReader br; StringTokenizer st;
            public FastReader(){
                br=new BufferedReader(new InputStreamReader(System.in)); }
            String next(){
                while(st==null || !st.hasMoreElements())
                    try{ st=new StringTokenizer(br.readLine()); }
                    catch(IOException e){ e.printStackTrace(); }
                return st.nextToken(); }
            int nextInt(){ return Integer.parseInt(next()); }
        }
        public static void main(String[] args) {
            FastReader in=new FastReader();
            PrintWriter out=new PrintWriter(System.out);
            int t=in.nextInt();
            while(t-->0){
                int n=in.nextInt(),
                        k=in.nextInt();
                if(k<n+n/2 || k>(long) n * 100_000 - (n/2) || (k-n/2%2)%2>0)
                    out.println(-1);
                else {
                    int ma=99998,
                            mi=k-n-n/2;
                    for(int i=0;i<n;i++) {
                        out.print(2-i%2+Math.min(ma, mi)+" ");
                        mi-=Math.min(ma, mi);
                    }
                    out.println();
                }
            } out.close();
        }
    }
