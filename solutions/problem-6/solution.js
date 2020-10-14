function sumOfSquares(n){

  let sum = 0

  for(let i = 1 ; i <= n ; i++){
    
      sum += i**2
  }  
  return sum;
}

function squareOfSums(n){

  let sum = 0

  for(let i = 1; i <= n; i++)
    sum += i

    return sum**2
}

function sumSquareDifference(n) { 

  return squareOfSums(n) - sumOfSquares(n)
}

sumSquareDifference(100)