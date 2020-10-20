
import java.util.Arrays;
import java.util.List;

/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.
*/
public class Solution001 {

    public static void main(String[] args) {
        System.out.println(solve(Arrays.asList(3,5),1000));
    }

    public static Integer solve(List<Integer> divisors,Integer range){
        divisors.sort(Integer::compareTo);
        Integer res = divisors.get(0);

        for(int i = divisors.get(0)+1;i < range;i++){
            res += hasDivisorInList(i,divisors) ? i : 0;
        }
        return res;
    }

    public static boolean hasDivisorInList(final Integer value,final List<Integer> divisors){
        for(Integer divisor : divisors){
            if(value % divisor == 0) return true;
        }
        return false;
    }

}
