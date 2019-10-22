
<?php

$count = 2; /*starting at 2 to pickup the first even number*/
$sum = 0;
$a = 1;
$b = 2;

while ($count < 4000000) {
        $sum = $a + $b;
        if ($sum % 2 == 0) {
                $count = $count + $sum
        }
        /*shift the variables to contain the new sum and the prior number before looping again */
        $a = $b;
        $b = $sum;
}


echo "The sum of even Fibonacci numbers between one and four million is " . $count;

?>
