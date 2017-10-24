//Sum of the multiples of 3 or 5 below 1000

function sumMultiplesOf3or5Below1000(){
  var multiples = [];
  
  for(i=0;i<1000;i++){
    if(i%3===0 || i%5===0){
      multiples.push(i);
    }
  }
  return sumArray(multiples);
  
  //sum an array of integers
  function sumArray(arr){ 
    return arr.reduce(function(sum, i){
      return sum + i;
    },0);
  }
}

sumMultiplesOf3or5Below1000() //Output-> 233168
