<?php

function fibonacci($number) {
	$previous = 1;
	$current = 0;
 	while ($number-- > 0) {
		[$previous, $current] = [$current, $previous + $current];
	}
 	return $current;
}

function calculate($limit) {
    $fib_number = 0;
    $res = 0;
    $index = 0;

    while ($fib_number < $limit) {
        $fib_number = fibonacci($index);
        if ($fib_number % 2 === 0) {
            $res += $fib_number;
        }
        $index++;
    }
    
    return $res;
}

print calculate(4000000) . PHP_EOL;

