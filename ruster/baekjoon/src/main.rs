#[allow(unused)]
use std::io::{self, BufReader};

#[allow(unused)]
use proconio::{input, marker::Chars, source::line::LineSource};

fn main() {
    //let mut stdin = LineSource::new(BufReader::new(io::stdin()));
    //macro_rules! input(($($tt:tt)*) => (proconio::input!(from &mut stdin, $($tt)*)));
    input! {
        s: Chars
    }

    let mut counter = vec![0; 26];

    for ch in s {
        let idx = (ch as u8 - 'a' as u8) as usize;
        counter[idx] += 1;
    }
    println!(
        "{}",
        counter
            .iter()
            .map(|num| num.to_string())
            .collect::<Vec<_>>()
            .join(" ")
    );
}
