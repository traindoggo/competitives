#[allow(unused)]
use std::io::{self, BufReader};

#[allow(unused)]
use proconio::{input, marker::Chars, source::line::LineSource};

fn main() {
    let mut stdin = LineSource::new(BufReader::new(io::stdin()));
    macro_rules! input(($($tt:tt)*) => (proconio::input!(from &mut stdin, $($tt)*)));

    loop {
        input! {
            a: i32,
            b: i32,
        }

        if a == 0 && b == 0 {
            break;
        }

        println!("{}", if a <= b { "No" } else { "Yes" })
    }
}
