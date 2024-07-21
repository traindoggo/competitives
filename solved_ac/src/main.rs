#[allow(unused)]
use proconio::{input, marker::Chars};

fn main() {
    loop {
        input! {
            a: i32,
            b: i32,
        }

        if a == 0 && b == 0 {
            break;
        }
        println!("{}", a + b);
    }
}
