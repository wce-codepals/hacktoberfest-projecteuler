class Solution {
  // num is the number that you want to calculate the sums to
  constructor(num) {
    this.num = num;
  }
  
  sumOfSquares() {
    let sum = 0;
    for (let i = 1; i <= this.num; i++) {
      sum += Math.pow(i, 2);
    }
    return sum;
  }
  
  squaresOfSums() {
    let sum = 0;
    for (let i = 1; i <= this.num; i++) {
      sum += i;
    }
    return Math.pow(sum, 2);
  }

  solve() {
    return this.squaresOfSums() - this.sumOfSquares();
  }

}

const solution = new Solution(100);
solution.solve();