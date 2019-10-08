<?php 
function sumMultiplesThreeAndFive($number){
  $sum = 0;
  for($i = 1; $i < $number; $i++) {
    if ($i % 3 == 0 || $i % 5 == 0)
      $sum += i;
  }
  return $sum;
};

$result = sumOfMultiplesOfThreeAndFive(1000);
echo $result;

?>