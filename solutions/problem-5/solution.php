<?php

/*

 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

   What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

function calculate($limit, $lcm) {
    if ($limit < 2) {
        return $lcm;
    }
    
    return calculate($limit - 1, lcm($limit, $lcm));
}

function gcd($a, $b) {
   if ($b == 0) return $a;

   return gcd($b, $a % $b);
}

function lcm($a, $b) {
    return $a * $b / gcd($a, $b);
}

function wrap($num) {
    return calculate($num, lcm($num, 1));
}

print wrap(20) . PHP_EOL;

