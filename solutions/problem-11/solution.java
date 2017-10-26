//https://projecteuler.net/problem=11
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;


public class Solution {


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int[][] in = new int[20][20];
        for (int i = 0 ; i < 20 ; i++){
            for (int j = 0 ; j < 20 ; j++){
                in[i][j] = sc.nextInt();
            }
        }

        int max = Integer.MIN_VALUE;
        int tmp = 0;

        for (int i = 0 ; i < 20 ; i++){
            for (int j = 0 ; j < 20 ; j++){
                if (i < 17){
                    tmp = in[i][j] * in[i+1][j] * in[i+2][j] * in[i+3][j];
                        if (tmp > max) max = tmp;
                }
        
                if (j < 17){
                    tmp = in[i][j] * in[i][j+1] * in[i][j+2] * in[i][j+3];
                    if (tmp > max) max = tmp;
                }
                
                if (j < 17 && i < 17){
                    tmp = in[i][j] * in[i+1][j+1] * in[i+2][j+2] * in[i+3][j+3];
                    if (tmp > max) max = tmp;
                }
                if (i < 17 && j > 2){
                   tmp = in[i][j] * in[i+1][j-1] * in[i+2][j-2] * in[i+3][j-3];
                    if (tmp > max) max = tmp;
                }
            }
        }

        System.out.println(max);
    
    }
}
