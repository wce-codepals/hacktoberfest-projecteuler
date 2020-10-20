
public class Smallests {
    /*2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

    What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
    */
    public static List<Integer> divisors ;
    public static void main(String[] args) {
        System.out.println(solve(1,20));
    }

    public static Integer solve(int min,int max){
        divisors = initList(min,max);
        int value = 1;
        while(!areAllDivisors(++value, divisors));
        return value;
    }

    public static boolean areAllDivisors(final int value,final List<Integer> divisors){
        int i = 0;
        while(i < divisors.size() && value % divisors.get(i++) == 0);
        return i >= divisors.size();
    }

    public static List<Integer> initList(int init,int end){
        List<Integer> integers= new ArrayList<>();
        while(init <= end){
            integers.add(init++);
        }
        return integers;
    }
}