//Add JavaScript solution to problem-1

function sum() {
    var sum = 0;
    // running a loop for numbers from 1 to 999
    for(var i=1; i < 1000; i++) {
        //checking if the number is a factor of 3 or 5
        if (i % 3 === 0 || i % 5 === 0) {
            //adding the number to sum if it is
            sum += i;
        }
        //returning the sum
        return sum;
    }
}
