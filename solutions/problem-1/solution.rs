
fn solve() -> i64 {
    (0..1000).filter(|n| (n % 3 == 0) || (n % 5 == 0)).sum()
}

fn main() {
    println!("{}", solve())
}

#[cfg(test)]
mod tests {
    use std::fs::File;
    use std::io::Read;
    use super::solve;

    fn get_answer() -> i64 {
        let mut f = File::open("answer").expect("answer file not found");
        let mut contents = String::new();
        f.read_to_string(&mut contents)
            .expect("something went wrong reading the answer");

        return contents.trim().parse::<i64>().unwrap()
    }

    #[test]
    fn answer() {
        assert_eq!(get_answer(), solve());
    }
}
