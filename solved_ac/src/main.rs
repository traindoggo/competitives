#[allow(unused)]
use proconio::{input, marker::Chars};

fn main() {
    input! {
        a: i32,
        b: i32,
    }

    println!("{}", a + b);
    println!("{}", a - b);
    println!("{}", a * b);
    println!("{}", a / b);
    println!("{}", a % b);
}
