<?php

function isPalindrome($number) {
    $str = (string) $number;
    
    $strlen = strlen($str);
    $half = ceil($strlen / 2);

    for($i = 0; $i <= $half; $i++) {
        if ($str[$i] != $str[$strlen - 1 - $i]) {
            return false;
        }
    }
    
    return true;
}

function calculate($limit) {
    $res = 0;
    $a = $limit;
    $b = $limit;
    
    while ($a > 99) {
        while ($b > 99) {
            $mult = $a * $b;
            if (isPalindrome($mult)) {
                $res = $mult < $res ? $res : $mult;
            }
            $b--;
        }
        $a--;
        $b = $limit;
    }

    return $res;
}

print calculate(999);

