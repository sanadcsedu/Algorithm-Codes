import java.math.BigInteger;
import java.util.Scanner;


public class Main {

	public static void main(String[] args)
	{
		Scanner input = new Scanner (System.in);
		BigInteger ans, product;
		int[] a = new int [105];
		int i, n;
		while(input.hasNext())
		{
			for(i=0; ; i++)
			{
				a[i] = input.nextInt();
				if(a[i] == -999999)break;
			}
			n = i;
			ans = BigInteger.valueOf(a[0]);
			for(i=0 ; i<n; i++)
	        {
	            product = BigInteger.valueOf(a[i]);
	            ans = product.max(ans);
	            for(int j = i+1; j<n; j++)
	            {
	                product = product.multiply(BigInteger.valueOf(a[j]));
	                ans = product.max(ans);
	            }
	        }
			System.out.println(ans);
		}
	}
}
