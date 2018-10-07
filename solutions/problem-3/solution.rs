fn main() {
    let mut n = 600851475143u64;
    let mut prime_factors = Vec::new();
    while n % 2 == 0 {
        prime_factors.push(2);
        n = n / 2;
    }

    for i in (3..(n as f64).sqrt() as u64).step_by(2) {
        while n % i == 0 {
            prime_factors.push(i);
            n = n / i;
        }
    }

    println!("{:?}", prime_factors)
}
