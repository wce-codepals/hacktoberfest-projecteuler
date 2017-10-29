import java.util.*;

public static void main(String[] args) {
    Scanner in = new Scanner(System.in);

    int n = 1000;
    int k = 13;
    String num = in.next();

    char c[]=num.toCharArray();
    int a[]=new int [c.length];
    for(int i=0;i<c.length;i++) {
        a[i]=Integer.parseInt(String.valueOf(c[i]));
    }
    int max=0;
    
    for(int i=0;i<a.length-k;i++) {
        int temp=1;
        for(int j=i;j<k+i;j++) {
            temp=temp*a[j];
        }
        if(max<temp)
            max=temp;
    }
    System.out.println(max);
}