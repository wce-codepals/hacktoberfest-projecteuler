class Solution {
  // num is the number you want to calculate to
  constructor(num) {
    this.num = num;
    this.range = [];
  }

  calculateSmallestMultiple() {
    for (let smallestMultiple = 1; smallestMultiple < Number.MAX_SAFE_INTEGER; smallestMultiple++) {
      for (let j = 1; j <= this.num; j++) {
        if (smallestMultiple % j !== 0) {
          break;
        } else if (j === this.num && smallestMultiple % j === 0) {
          return smallestMultiple;
        }
      }
    }
  }
}

const solution = new Solution(20);
solution.calculateSmallestMultiple();