#[allow(unused)]
use proconio::{input, marker::Chars};

fn main() {
    input! {
        n: i32,
    }

    let is_leapyear: bool = (n % 4 == 0 && n % 100 != 0) || n % 400 == 0;
    println!("{}", if is_leapyear { 1 } else { 0 });
}
