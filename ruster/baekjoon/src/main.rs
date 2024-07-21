#[allow(unused)]
use std::io::{self, BufReader};

#[allow(unused)]
use proconio::{input, marker::Chars, source::line::LineSource};

fn main() {
    //let mut stdin = LineSource::new(BufReader::new(io::stdin()));
    //macro_rules! input(($($tt:tt)*) => (proconio::input!(from &mut stdin, $($tt)*)));
    input! {
        _: usize,
        digits: Chars,
    }

    let mut ans: i32 = 0;
    for d in digits {
        ans += (d as u8 - '0' as u8) as i32;
    }
    println!("{}", ans);
}
