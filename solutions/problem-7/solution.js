/*
  Node program to output the 10001st prime number (using Sieve of Eratosthenes)

	Language: JavaScript
	Usage: node sieve.js 10001
*/
"use strict"
let num = +process.argv[2];
//  upper limit for nth prime number is
//    p(n) < n ln( n ln(n) )
//  see https://www.quora.com/What-are-good-ways-to-find-the-nth-prime-number-in-the-fastest-way-This-question-is-asked-in-the-context-of-an-interview-What-if-it-is-not-allowed-to-compute-all-n-prime-numbers/answer/Jason-Martin
let upperLimit = num * Math.log( num * Math.log(num) );
upperLimit = Math.ceil(upperLimit);

//  initialize object array with { val, marked } pairs
let arr = [
  {
    "val" : 0,
  	"marked" : true
  },
  {
  	"val" : 1,
  	"marked" : true
  }
];

for ( let i = 2; i <= upperLimit; i++ ) {
	arr.push({
		"val" : i,
		"marked" : false
	});
}

let stopComputing = false;
let currentFactor = 2;
let i = 0;
//start while loop
while ( !stopComputing ) {
	i = 2 * currentFactor;

  //  mark all multiples of currentFactor
	while ( i < arr.length ) {
		arr[i].marked = true;
		i += currentFactor;
	}

	for ( let k = currentFactor + 1 ; k < arr.length; k++ ) {

    //  stop computing if reached end of array
    if ( k === arr.length - 1 ) {
			stopComputing = true;
		}

    //  else, set next unmarked number as currentFactor
    if ( arr[k].marked == false ) {
			currentFactor = k;
			break;
		}
	} // end of for loop
} // end of outer while loop


//  Find nth unmarked number in the array, which is the nth prime number
let answerIndex;
let count = 0;

for ( answerIndex = 0; answerIndex < arr.length; answerIndex++ ) {
  if( arr[answerIndex].marked === false ) {
    count++;
    if ( count === num ) {
      break;
    }
  }
}
console.log(arr[answerIndex].val);
