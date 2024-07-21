#[allow(unused)]
use proconio::{input, marker::Chars};

fn main() {
    input! {
        n: usize,
        si: [(i32, i32); n],
    }

    for (a, b) in si {
        println!("{}", a + b);
    }
}
