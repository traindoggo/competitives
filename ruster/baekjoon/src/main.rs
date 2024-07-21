#[allow(unused)]
use std::io::{self, BufReader};

#[allow(unused)]
use proconio::{input, marker::Chars, source::line::LineSource};

fn main() {
    //let mut stdin = LineSource::new(BufReader::new(io::stdin()));
    //macro_rules! input(($($tt:tt)*) => (proconio::input!(from &mut stdin, $($tt)*)));
    input! {
        n: usize,
    }

    for i in 0..n {
        println!("{}", "*".repeat(n - i));
    }
}
