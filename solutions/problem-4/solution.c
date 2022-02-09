#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *strrev(char *);
int ifPalin(char *);
void main(){
	int i, j, it=0;
	char buff[7];
	for(i=999;i>900;i--)	{
		for(j=999;j>900;j--){	
			it++;
			sprintf(buff,"%d",i*j);
			if(ifPalin(buff)==1){
				goto a;
			}
		}
	}
	a: printf("%s\n", buff);
}
char *strrev(char *str){
     char *p1, *p2;
      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2){
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}
int ifPalin(char *a){
char b[7];
strcpy(b,a);
strrev(b);
	if((strcmp(a,b))==0)
		return 1;
	else
		return 0;
}
