function factor(n) {
    var factors= [ ];
    for (var i = 1; i <= n; i++) {
        if (n % i === 0) {
        factors.push(i);
        }
    }
   return factors;
}

function Prime(num) {
    for (var i=2; i < num; i++) {
    if (num % i === 0) {
        return false;
    }
  }
  return number > 1;
}

function primes(factors) {
    var primes = [ ];
    for (var i=1; i<factors.length; i++) {
    if (Prime(factors[i])) {
        primes.push(factors[i]);
    }
  }
  return primes;
}

var factors = factor(600851475143);
var arr = primes(factors);
console.log(arr[arr.length-1]);