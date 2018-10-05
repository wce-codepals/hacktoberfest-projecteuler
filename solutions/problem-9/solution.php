<?php

define("LIMIT", 1000);

function findProdTriplets($limit) {    
    $res = 1;
    
    $a = 1;
    while ($a < $limit - 2) {
        $b = $a + 1;
        while ($b < $limit - 1) {
            $c = sqrt($a ** 2 + $b ** 2);
            if (($a + $b + $c) == LIMIT) {
                $res = $a * $b * $c;
            }
            $b++;
        }
        $a++;
    }
    
    return $res;
}

print findProdTriplets(LIMIT);

