var n = 600851475143;
var x = n;
var i = 2;
while(i<x) {
	while(x % i === 0) {
		(function(n) {
			x = n;
		})
    (x / i)
	}
	i++;
}
console.log(x);
