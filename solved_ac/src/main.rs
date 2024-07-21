#[allow(unused)]
use proconio::{input, marker::Chars};

fn main() {
    input! {
        n: usize,
        si: [i32; n],
    }

    println!("{} {}", si.iter().min().unwrap(), si.iter().max().unwrap());
}
