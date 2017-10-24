var sumOfMultiplesOf3And5 = function (upperLimit) {
    var sum = 0;
    for (var i = 0; i < upperLimit; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }
    return sum;
}

console.log(sumOfMultiplesOf3And5(1000));
