//find the first n occurences of numbers that are 
//a multiple of 3 or 5, and add them
function firstN_threeOrFiveMultiples_Sum (n) {
  var result = 0;
  for(i = 1; i < n; i++) {
    if (i % 3 == 0 || i % 5 == 0)
      result += i;
  }
  return result;
};



