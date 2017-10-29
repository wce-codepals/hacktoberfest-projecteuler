function greatest_coin(coin_range) {
	if (coin_range === 0) {
		return 0;
	} else if (coin_range === 1) {
		return 1;
	} else if (coin_range === 2) {
		return 2;
	} else if (coin_range === 3) {
		return 5;
	} else if (coin_range === 4) {
		return 10;
	} else if (coin_range === 5) {
		return 20;
	} else if (coin_range === 6) {
		return 50;
	} else if (coin_range === 7) {
		return 100;
	} else if (coin_range === 8) {
		return 200;
	}
}

function cc() {
	function helper(amt, coin_range) {
		if (amt === 0) {
			return 1;
		} else if (amt < 0 || coin_range === 0) {
			return 0;
		} else {
			return helper(amt - greatest_coin(coin_range), coin_range) + 
				     helper(amt, coin_range - 1);
		}
	}
	return helper(200, 8);
}

cc();