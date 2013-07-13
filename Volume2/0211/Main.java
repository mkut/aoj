import java.io.*;
import java.util.*;
import java.math.*;

public class Main
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		for(int n = sc.nextInt(); n != 0; n = sc.nextInt())
		{
			BigInteger[] d = new BigInteger[n];
			BigInteger[] v = new BigInteger[n];
			for(int i = 0; i < n; i++)
			{
				d[i] = BigInteger.valueOf(sc.nextInt());
				v[i] = BigInteger.valueOf(sc.nextInt());
			}
			for(int i = 0; i < n; i++)
				for(int j = 0; j < n; j++)
					if(i != j)
						d[i] = d[i].multiply(v[j]);
			
			BigInteger LCM = BigInteger.ONE;
			for(int i = 0; i < n; i++)
				LCM = lcm(LCM, d[i]);
			
			for(int i = 0; i < n; i++)
				System.out.println(LCM.divide(d[i]));
		}
	}
	
	public static BigInteger gcd(BigInteger x, BigInteger y)
	{
		return y.equals(BigInteger.ZERO) ? x : gcd(y, x.mod(y));
	}
	
	public static BigInteger lcm(BigInteger x, BigInteger y)
	{
		return x.multiply(y).divide(gcd(x, y));
	}
}