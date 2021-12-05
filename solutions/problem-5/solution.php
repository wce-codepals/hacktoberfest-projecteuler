<?php
ini_set('max_execution_time', 120); /*takes longer to run than the default 30 seconds*/

$count = 25; /*start at 25 since we can ignore 1-20 and we know we have to increment by 5*/
$test = 0;
$success = 0;

do{
                for($i=1;$i<=20;$i++){
                                        $test = $test + ($count % $i);
                                                }
                        if ($test == 0){
                                                $success = 1;
                                                                break;
                                                        }
                        $count = $count + 10; /*incrementing by 10 since one of the divisors is 10, it will end in a zero no matter what*/
                        $test = 0; /*reset the test for next number */
} while ($success != 1);

echo "The largest integer divisible by numbers 1 through 20 is " . $count;

?>
