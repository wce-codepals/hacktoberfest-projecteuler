class solution
 {
   public static void main(String args[])
     {
       
       int value1=0;
       for(int i=100;i<=999;i++)
         {
            for(int j=i;j<=999;j++)
             {
                int value=i*j;
                StringBuilder sb1=new StringBuilder(""+value);
                String sb2=""+value;
                sb1.reverse();
                if(sb2.equals(sb1.toString()) && value1 < value)
                value1=value;
              }
              
            }
          System.out.println(value1);
         }
        }
