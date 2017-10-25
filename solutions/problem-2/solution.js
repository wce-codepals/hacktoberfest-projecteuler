//Sum of even fibonacci numbers below 4 million
function sumEvenFibonaccisBelow4mil(){
  
  var fibonacciNumbers = findFibonacciNos(4000000);
  var evenFibonacciNumbers = findEvenEl(fibonacciNumbers);
  
  return sumArray(evenFibonacciNumbers);
  
  function findFibonacciNos(number){
    var fibonacciNos = [1,2];
    var lastFibonacci = fibonacciNos[fibonacciNos.length-1];
    for(i=1;lastFibonacci<number;i++){
      var previous = fibonacciNos[i-1];
      var next = fibonacciNos[i]+previous;
      fibonacciNos.push(next);
    }
    return fibonacciNos;
  }
    
  function findEvenEl(array){
    return array.filter(function(el){
      return el%2===0;
    });
  }
  
  function sumArray(array){
    return array.reduce(function(sum, i){
      return sum + i;
    },0);
  }
  
}
