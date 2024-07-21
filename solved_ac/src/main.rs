#[allow(unused)]
use proconio::{input, marker::Chars};

fn main() {
    input! {
        a: i64,
        b: i64,
        c: i64,
    }

    let mut counter = vec![0; 10];
    let res = (a * b * c).to_string();

    for ch in res.chars() {
        let idx = (ch as u8 - '0' as u8) as usize;
        counter[idx] += 1;
    }
    eprintln!("{:?}", counter);

    for c in counter {
        println!("{}", c);
    }
}
