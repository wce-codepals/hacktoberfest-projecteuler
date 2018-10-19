function fib (n: number): number {
    return n < 1 ? 1 : fib(n - 1) + fib(n - 2);
}

function fibWithLimit (limit: number) {
    let sum = 0;
    let currentNumber = 0;
    let fibVal = 0;
    while (fibVal < limit) {
        fibVal = fib(currentNumber);
        if (fibVal % 2 == 0) {
            sum += fibVal;
        }
        currentNumber++;
    }
    return sum;
}

console.log(fibWithLimit(4000000));