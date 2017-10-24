class Solution{
	public static void main(String args[]){
		int i=1,j=1,k=0,sum=0;
		while(k<=4000000){
			if(k%2==0){
			sum=sum+k;
			}
			i=j;
			j=k;
			k=i+j;		
		}
		System.out.println(sum);	
	}
}
