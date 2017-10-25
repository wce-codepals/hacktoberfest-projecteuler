
import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;


class Solution
{
	static BigInteger choose(int n,int k){
		// System.out.println("hello");
		if(k>n-k) k = n-k;
		BigInteger result = new BigInteger("1"); 
		for(int i=1;i<=k;i++){
		// System.out.println(i);	
			result = result.multiply(BigInteger.valueOf(n-k+i));
			result = result.divide(BigInteger.valueOf(i));
		}
		return result;
	}
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		int n,m;
		n=20;
		m=20;
		BigInteger nck = choose(n+m,n);
		System.out.println(nck.toString());
	}
}