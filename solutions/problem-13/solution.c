# include <stdio.h>

void SumTwoNum(char A[],char B[],char C[]);
void sum(char A[],char B[],char C[]);

int main()
{
	char A[10000],B[10000],C[10000];
	int i;
	sum(A,B,C);
	for(i=0;i<10;i++)
		printf("%c",C[i]);
	printf("\n");
	return 0;
}

void sum(char A[],char B[],char C[])
{
	int i,j,k;
	scanf("%d",&k);
	getchar();
	scanf("%[^\n]s",A);
	for(i=1;i<k;i++)
	{
		SumTwoNum(A,B,C);
		for(j=0;C[j]!='\0';j++)
		{
			A[j]=C[j];
		}
		A[j]='\0';
	}
}

void SumTwoNum(char A[],char B[],char C[])
{
	int i,j,len1,len2;

	getchar();
	scanf("%s",B);

	for(i=0;A[i]!='\0';i++);
	len1=i;
	for(i=0;B[i]!='\0';i++);
	len2=i;
	
	int sum=0,carry=0,k=0;
	for(i=len1-1, j=len2-1 ; i>=0 && j>=0 ; i-- , j--)
	{
		sum=((A[i]-'0') + (B[j]-'0') + carry)%10;
		C[k]=sum+'0';
		carry=((A[i]-'0') + (B[j]-'0') + carry)/10;
		k++;
	}
	if(i==-1)
	{
		for(;j>=0;j--)
		{
			sum=((B[j]-'0') + carry)%10;
			C[k]=sum+'0';
			carry=(B[j] + carry - '0')/10;
			k++;
		}
	}
	if(j==-1)
	{
		for(;i>=0;i--)
		{
			sum=((A[i]-'0')  + carry)%10;
			C[k]=sum+'0';
			carry=(A[i] + carry - '0')/10;
			k++;
		}
	}
	if(carry==0)
	{
		C[k]='\0';
	}
	else
	{
		C[k]=carry+'0';
		C[k+1]='\0';
	}

	char c;
	for(i=0;C[i]!='\0';i++);
	i=i-1;
	j=0;
	for(;j<i;i--,j++)
	{
		c=C[i];
		C[i]=C[j];
		C[j]=c;
	}
}
