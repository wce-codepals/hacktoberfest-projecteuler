let isDivisble = false;
const MAX_NUMBER = 21;

function euler_5() {
	for(let i = 1; !isDivisble; i++) {
		if (divisbleByNumbers(i)) {
			isDivisble = true;
			console.log("IsDivisble " + isDivisble + " number : " + i);
		}
	}
}

function divisbleByNumbers(number) {
	for(let i = 1; i < MAX_NUMBER; i++) {
		if (number % i !== 0) {
			return false;
		}
	}
	return true;
}

euler_5();

//Solution is 232792560