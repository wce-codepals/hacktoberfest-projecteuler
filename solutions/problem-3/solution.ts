function largest_prime_factor(n: number): number {
    let i = 2;
    while (i * i <= n) {
        if (n % i !== 0) {
            i++;
        } else {
            n = Math.floor(n / i);
        }
    }
    return n;
}

console.log(largest_prime_factor(1000));
