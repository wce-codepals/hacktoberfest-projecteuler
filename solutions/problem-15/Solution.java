
import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;


class Solution
{
	//calculates nCk
	static BigInteger choose(int n,int k){
		
		if(k>n-k) k = n-k;
		BigInteger result = new BigInteger("1"); 
		for(int i=1;i<=k;i++){	
			result = result.multiply(BigInteger.valueOf(n-k+i));
			result = result.divide(BigInteger.valueOf(i));
		}
		return result;
	}
	public static void main (String[] args) throws java.lang.Exception
	{
		// n and m denote the dimensions of the grid.
		// the number of routes equals to nCk i.e. choose k from n.
		int n,m;
		n=20;
		m=20;
		BigInteger nck = choose(n+m,n);
		System.out.println(nck.toString());
	}
}