#include<stdio.h>
      main()
      {
             int counter=2,i,a,b;
             int x[1000],y[1000],z[1000];
             for(i=0;i<1000;i++)x[i]=y[i]=z[i]=0;
             z[999]=1;
             y[999]=1;
             do
             {
                         for(a=999;a>=0;a--)
                         {
                                        x[a]=z[a];
                                        z[a]=z[a]+y[a];
                                        y[a]=x[a];
                          }
                          counter++;
                          for(b=998;b>=0;b--)
                           {
                                          x[b]+=x[b+1]/10;
                                          x[b+1]%=10;
                                          y[b]+=y[b+1]/10;
                                          y[b+1]%=10;
                                          z[b]+=z[b+1]/10;
                                           z[b+1]%=10;
                            }

                   }while(z[0]==0);
                   printf("%i",counter);

       }
