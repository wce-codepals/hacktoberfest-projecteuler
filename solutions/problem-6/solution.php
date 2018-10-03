<?php

function calc($num) {
    $sum1 = 0;
    $sum2 = 0;

    while($num > 0) {
        $sum1 += $num ** 2;
        $sum2 += $num;
        $num--;
    }
    
    $sum2 = $sum2 ** 2;
    
    return $sum2 - $sum1;
}

print calc(100) . PHP_EOL;

