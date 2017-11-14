//Add JavaScript solution to problem-3
function findLargestPrimeNumbers(_number) {
  let number = _number;
  let primeFactors = [];

  for (let i=0; i <= number; i++) {
    if (number % i === 0) {
      if (i % 2 !== 0 && i > 1) {
        primeFactors.push(i);
        number = number / i;
      }
    }
  }

  return primeFactors
}
