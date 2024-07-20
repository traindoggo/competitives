#[allow(unused)]
use std::io::{self, BufReader};

#[allow(unused)]
use proconio::{input, marker::Chars, source::line::LineSource};

fn main() {
    let mut stdin = LineSource::new(BufReader::new(io::stdin()));
    macro_rules! input(($($tt:tt)*) => (proconio::input!(from &mut stdin, $($tt)*)));
    loop {
        input! {
            n: usize,
        }

        if n == 0 {
            break;
        }

        input! {
            ai: [i32; n],
        }

        let mut mx: i32 = 0;

        for w in ai.windows(3) {
            let sum = w.into_iter().sum::<i32>();
            mx = mx.max(sum);
        }

        println!("{}", mx);
    }
}
