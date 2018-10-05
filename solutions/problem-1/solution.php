<?php

function calculate($limit) {
    $tmp = $res = 0;

    while ($tmp < $limit) {
        if ($tmp % 3 === 0 || $tmp % 5 === 0) {
            $res += $tmp;
        }
        $tmp++;
    }

    return $res;
}

print calculate(1000) . PHP_EOL;

