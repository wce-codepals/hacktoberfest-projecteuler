struct Fibonacci {
	curr: u64,
	next: u64,
}

impl Fibonacci {
    pub fn new() -> Self {
        Fibonacci {
            curr: 1,
            next: 1,
        }
    }
}

// https://github.com/rust-lang/rust-by-example/blob/master/src/trait/iter.md
impl Iterator for Fibonacci {
	type Item = u64;

	fn next(&mut self) -> Option<u64> {
        let new_next = self.curr + self.next;

        self.curr = self.next;
        self.next = new_next;

        Some(self.curr)
	}
}

fn solve() -> u64 {
    Fibonacci::new()
        .take_while(|x| *x < 4000000)
        .filter(|x| x % 2 == 0)
        .sum()
}

fn main() {
    println!("{}", solve())
}

#[cfg(test)]
mod tests {
    use super::solve;

    #[test]
    fn answer() {
        assert_eq!(solve(), 4613732);
    }
}
