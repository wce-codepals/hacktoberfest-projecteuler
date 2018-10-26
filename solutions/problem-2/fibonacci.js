var a=1,b=2,c=0,sum=2, nos = [ ];
while(c<4000000)
  {
  c=a+b;
  if(c%2==0)
    {  
    sum += c;
    }
    
  a=b;
  b=c;
  }
document.write(sum); 
