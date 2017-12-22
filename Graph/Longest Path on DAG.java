
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 *
 * @author sanad_csedu
 */
public class Main {


    public static void main(String[] args) {

        InputStream inputstream = System.in;
        InputReader in = new InputReader(inputstream);
        DAG solver = new DAG();
        solver.solve(in);
    }
}
class DAG
{
    int r, c;
    int a[][] = new int[105][105];
    int dp[][] = new int[105][105];
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    public void solve(InputReader in)
    {
        int t, tcase,i, j, z;
        tcase = in.nextInt();
        String name;
        for(t=1; t<= tcase; t++)
        {
            name = in.next();
            r = in.nextInt();
            c = in.nextInt();
            reset();
            for(i=0; i<r; i++)
            {
                for(j=0; j<c; j++)
                {
                    a[i][j] = in.nextInt();
                }
            }
            int max = -1;
            for(i=0; i<r; i++)
            {
                for(j=0; j<c; j++)
                {
                    z = f(i, j);
                    if(max < z)
                    {
                        max = z;
                    }
                }
            }
            max++;
            System.out.println(name + ": " + max);
        }
    }
    public void reset()
    {
        for(int i=0; i<=r; i++)
        {
            Arrays.fill(dp[i], -1);
        }

    }
    public int f(int x, int y)
    {
        if(dp[x][y] != -1) return dp[x][y];
        int ret = 0, nx, ny;
        for(int i=0; i<4; i++)
        {
            nx = x + dx[i];
            ny = y + dy[i];
            if(nx>=0 && nx<r && ny>=0 && ny<c && (a[x][y] < a[nx][ny]) )
            {
                ret = Math.max(ret, 1 + f(nx, ny));
            }
        }
        return dp[x][y] = ret;

    }
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    }
