#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void num(long long a)
{
    int p,q,r;
    p=a/100;
    if(p>0)
        {
        switch(p)
            {
    case 1:
        printf("One ");
        break;
    case 2:
        printf("Two ");
        break;
    case 3:
        printf("Three ");
        break;
    case 4:
        printf("Four ");
        break;
    case 5:
        printf("Five ");
        break;
    case 6:
        printf("Six ");
        break;
    case 7:
        printf("Seven ");
        break;
    case 8:
        printf("Eight ");
        break;
    case 9:
        printf("Nine ");
        }
        printf("Hundred ");
    }
      p=a%100;
    if(p<=20)
        {
        switch(p)
            {
    case 1:
        printf("One ");
        break;
    case 2:
        printf("Two ");
        break;
    case 3:
        printf("Three ");
        break;
    case 4:
        printf("Four ");
        break;
    case 5:
        printf("Five ");
        break;
    case 6:
        printf("Six ");
        break;
    case 7:
        printf("Seven ");
        break;
    case 8:
        printf("Eight ");
        break;
    case 9:
        printf("Nine ");
    case 10:
        printf("Ten ");
        break;
    case 11:
        printf("Eleven ");
        break;
    case 12:
        printf("Twelve ");
        break;
    case 13:
        printf("Thirteen ");
        break;
    case 14:
        printf("Fourteen ");
        break;
            case 15:
        printf("Fifteen ");
        break;
            case 16:
        printf("Sixteen ");
        break;
            case 17:
        printf("Seventeen ");
        break;
            case 18:
        printf("Eighteen ");
        break;
            case 19:
        printf("Nineteen ");
        break;
            case 20:
        printf("Twenty ");
        break;
        }
    }
    if(p>20)
        {
        q=p/10;
        r=p%10;
        switch(q)
            {
    case 2:
        printf("Twenty ");
        break;
    case 3:
        printf("Thirty ");
        break;
    case 4:
        printf("Forty ");
        break;
    case 5:
        printf("Fifty ");
        break;
    case 6:
        printf("Sixty ");
        break;
    case 7:
        printf("Seventy ");
        break;
    case 8:
        printf("Eighty ");
        break;
    case 9:
        printf("Ninety ");
        }
        switch(r)
       {
    case 1:
        printf("One ");
        break;
    case 2:
        printf("Two ");
        break;
    case 3:
        printf("Three ");
        break;
    case 4:
        printf("Four ");
        break;
    case 5:
        printf("Five ");
        break;
    case 6:
        printf("Six ");
        break;
    case 7:
        printf("Seven ");
        break;
    case 8:
        printf("Eight ");
        break;
    case 9:
        printf("Nine ");
        }
        
    }
}
int main() 
{
    int t,i,j;
    long long n;
    scanf("%d",&t);
    for(i=0;i<t;i++)
        {
        scanf("%Ld",&n);
        if(n==0)
            printf("Zero\n");
        else
       {
        if(n>=pow(10,9))
         {
            num(n/(long long)pow(10,9));
            printf("Billion ");
        }
        n=n%(long long)pow(10,9);
        if(n>=pow(10,6))
         {
            num(n/(long long)pow(10,6));
            printf("Million ");
        }
        n=n%(long long)pow(10,6);
        if(n>=pow(10,3))
         {
            num(n/(long long)pow(10,3));
            printf("Thousand ");
        }
        n=n%(long long)pow(10,3);
        num(n);
        printf("\n");
    }
    }    
    return 0;
}

