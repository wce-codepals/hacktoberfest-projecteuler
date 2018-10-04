<?php

function calc($limit) {
    // As we need get prime number more then 2, we can skip it in checkng.
    // So we start from number 3 and it's second prime number.
    $i = 2;
    $tmp = 3;
    while ($i < $limit) {
        $tmp += 2;
        if (isPrime($tmp)) {
            $i++;
        }
    }
    
    return $tmp;
}

function isPrime($num) {
    if ($num % 2 === 0) {
        return false;
    }


    $root = floor(sqrt($num));
    for ($var = 3; $var <= $root; $var += 2) {
        if ($num % $var === 0) {
            return false;
        }
    }
    
    return true;
}

print calc(10001). PHP_EOL;

