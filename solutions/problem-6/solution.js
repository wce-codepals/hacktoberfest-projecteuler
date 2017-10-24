function SumSquareDifference(arr) {
    /* By multinomial theorem, (x[1] + x[2] + ... + x[n])^2 
     * = x[1]^2 + x[2]^2 + ... + x[n]^2 
     *   + (2!)/(1!1!) * x[1] * x[2] + (2!)/(1!1!) * x[1] * x[3] + ... (2!)/(1!1!) * x[1] * x[n] 
     *   + ... + (2!)/(1!1!) * x[n-1] * x[n]
     * = x[1]^2 + x[2]^2 + ... + x[n]^2 
     *   + 2 * (x[1] * x[2]+ x[1] * x[3] + ... x[n-1] * x[n])
     * Therefore the difference between square of sum and sum of square 
     * = 2 * (x[1] * sum(x[2] ... x[n]) + x[2] * sum(x[3] ... x[n]))
     */

    return 2 * arr.reduce((accu, cur, curIdx, arr) => {
        return accu + cur * sum(arr.slice(curIdx + 1))
    }, 0);
}

function sum(arr) {
    return arr.reduce((acc, cur) => {
        return acc + cur;
    }, 0);
}


var arr = new Array(100);
for (var i =1; i <= 100; i++) {
    arr[i-1] = i;
}
// apply SumSquareDifference on [1,2,3, ... , 100] and get the answer
console.log(SumSquareDifference(arr));