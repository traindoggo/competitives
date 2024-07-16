#[allow(unused_imports)]
use proconio::{
    fastout, input,
    marker::{Chars, Usize1},
};

fn min(a: i32, b: i32) -> i32 {
    if a > b {
        b
    } else {
        a
    }
}

fn main() {
    input! {
        red: i32,
        green: i32,
        blue: i32,
        c: String,
    }

    let ans = if c == "Blue" {
        min(red, green)
    } else if c == "Red" {
        min(blue, green)
    } else {
        min(red, blue)
    };

    println!("{}", ans);
}
