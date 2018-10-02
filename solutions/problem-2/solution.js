var fib = function (n) {
    if (n < 1) return 1;
    return fib(n - 1) + fib(n - 2);
}

var fibWithLimit = function (limit) {
    var sum = 0;
    var currentNumber = 0;
    var fibVal = 0;
    while (true) {
        fibVal = fib(currentNumber);
        if (fibVal >= limit) break;
        if (fibVal % 2 == 0) sum += fibVal;
        currentNumber++;
    }
    return sum;
}

console.log(fibWithLimit(4000000));