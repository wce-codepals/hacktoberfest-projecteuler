/**
 *
 * @author namhsuyA
 */
public class FactorialDigitSum {
    private final int digit;

    public FactorialDigitSum(int digit) {
        this.digit = digit;
    }
    
    /**
     * 
     * @return factorial sum
     */
    public int getFactorialDigitSum(){
        //variable to store factorial
        int var = 1;
        String digits;
        for (int i = 1; i <= digit; i++) {
            var*=i;
        }
        digits = String.valueOf(var);
        
        //re initializing variable to store factorial sum
        var=0;
        for (String string : digits.split("")) {
            var+=Integer.parseInt(string);
        }
        return var;
    }   
}
