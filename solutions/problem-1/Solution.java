public class Solution {

    public static void main(String[] args) {
    	/*
    	 *	print the sum of all the numbers below 1000,
    	 *	that are multiple of 3 or 5
    	 */
    int sum=0;
    for(int i=1;i<1000;i++){
    	if(i%3==0 || i%5==0 ){
    		sum+=i;
    	}
    }
    	System.out.println(sum);
    }
}
