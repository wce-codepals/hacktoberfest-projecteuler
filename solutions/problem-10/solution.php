<?php

function isPrime($num) {
    $root = floor(sqrt($num));

    for ($var = 3; $var <= $root; $var += 2) {
        if ($num % $var === 0) {
            return false;
        }
    }
    
    return true;
}

function getSumPrimesBelow($limit) {
    $sum = 2;

    $tmp = 3;
    while ($tmp < $limit) {
        if (isPrime($tmp)) {
            $sum += $tmp;
        }
        $tmp += 2;
    }
    
    return $sum;
}

print getSumPrimesBelow(2000000) . PHP_EOL;

