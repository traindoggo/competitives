#[allow(unused)]
use std::io::{self, BufReader};

#[allow(unused)]
use proconio::{input, marker::Chars, source::line::LineSource};

fn main() {
    // let mut stdin = LineSource::new(BufReader::new(io::stdin()));
    // macro_rules! input(($($tt:tt)*) => (proconio::input!(from &mut stdin, $($tt)*)));

    input! {
        tt: usize,
        ni: [i64; tt],
    }

    for t in 0..tt {
        println!("{}", fact(ni[t] as i64) % 10);
    }
}

fn fact(t: i64) -> i64 {
    let mut ans: i64 = 1;

    for i in 1..=t {
        ans *= i;
    }

    ans
}
