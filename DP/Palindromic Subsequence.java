import java.io.BufferedReader;
import java.io.IOException;
import java.util.Arrays;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {

        TaskA solver = new TaskA();
        solver.solve();
    }
}
class  TaskA
{
    String str = new String();
    int dp[][] = new int[100][100];
    int n;
    public void solve() throws IOException {

        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        int tcase = Integer.parseInt(bf.readLine());
        int i, ans;

        for (int t=0; t< tcase; t++)
        {
            str = bf.readLine();
            n = str.length();
            for(i=0; i <= n+1; i++)
            {
                Arrays.fill(dp[i], -1);
            }
            ans = f(0, n);
            System.out.println(ans - 1);
        }
    }
    private int f(int start, int end)
    {
        if(dp[start][end] != -1) return dp[start][end];
        int ret = 0;
        if(start == end )return  ret = 1;
        if(start+1 == end)return ret = 2;
        ret = f(start + 1, end) + f(start, end -1);
        if( str.charAt(start) != str.charAt(end-1)) ret -= f(start + 1, end - 1);

        return dp[start][end] = ret;
    }

}

