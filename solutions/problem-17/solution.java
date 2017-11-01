public abstract class NumberLetterCounts {
    
    public static void main(String[] args) {
        
        int oneThroughNineLength = "onetwothreefourfivesixseveneightnine".length();
        int tenThroughNineteenLength = "teneleventwelvethirteenfourteenfifteensixteenseventeeneighteennineteen".length();
        int hundredAndLength = "hundredAnd".length();
        
        int oneThroughNinetyNineLength = (oneThroughNineLength * 9) + tenThroughNineteenLength + (10 * "twentythirtyfortyfiftysixtyseventyeightyninety".length());
        
        int oneThroughOneThousandLength = (hundredAndLength*99*9) + (oneThroughNinetyNineLength * 10) + (oneThroughNineLength * 100) + ("hundred".length() * 9) + "oneThousand".length();
        
        System.out.println(oneThroughOneThousandLength);
        
    }
    
}