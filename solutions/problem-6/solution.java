public class problem6 {
    static int squareSum(int num){
        num=(num * (num + 1) * (2 * num + 1)) / 6;
        return num;
    }
    static int square_sum(int n){
        n=(n * (n + 1)) / 2;  //sum of numbers
        n=n * n;  //square of num
        return n;
    }
    public static void main(String[] args) {
        System.out.println(Math.abs(square_sum(10) - squareSum(10)));//difference
    }
}
