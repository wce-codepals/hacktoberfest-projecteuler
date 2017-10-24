public final class eu_p002_sol {  
  
    public static void main(String[] args) {  
        System.out.println(new eu_p002_sol().run());  
    }  
public String run() {  
        int sum = 0;  
        for (int x = 0; ; x++) {  
            int fib = fibonacci(x);  
            if (fib > 4000000)  
                break;  
            if (fib % 2 == 0)  
                sum += fib;  
        }  
        return Integer.toString(sum);  
    }  
  
    private static int fibonacci(int n) {  
        if (n < 0 || n > 46)  
            throw new IllegalArgumentException();  
        int a = 0;  
        int b = 1;  
        for (int i = 0; i < n; i++) {  
            int c = a + b;  
            a = b;  
            b = c;  
        }  
        return a;  
    }  
} 
