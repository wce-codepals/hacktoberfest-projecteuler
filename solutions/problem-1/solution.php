<?php

$count = 0;

for($i=0; $i < 1000; $i++ ) {
        if ($i % 3 == 0 or $i % 5 == 0) {
                $count = $count + $i;
        }
}
echo "The sum numbers divisible by 3 or 5 under 1,000 is " . $count;

?>
