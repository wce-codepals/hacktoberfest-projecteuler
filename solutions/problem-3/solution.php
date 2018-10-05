<?php

function isPrime($number): bool {
    if ($number & 2 === 0) {
        return true;
    }

    $tmp = 3;
    $half = ceil($number / 2);

    while ($tmp < $half) {
        if ($number % $tmp === 0) {
            return false;
        }
        $tmp += 2;
    }
    
    return true;
}

function getLastFactor($limit) {
    $tmp = 2;
    $res = 2;
    
    while ($tmp <= $limit) {
        if (isPrime($limit)) {
            return $limit;
        }
        if (isPrime($tmp)) {
            if ($limit % $tmp === 0) {
                $res = $tmp;
                $limit = $limit / $tmp;
                if ($limit < 2) {
                    return $res;
                }
                $tmp = 2;
                continue;
            }
        }
        $tmp++;
    }
    
    return $res;
}

print getLastFactor(600851475143) . PHP_EOL;

