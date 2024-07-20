#[allow(unused)]
use proconio::{input, marker::Chars};

fn main() {
    input! {
       s: Chars,
    }

    let ans: String = s
        .iter()
        .map(|ch| {
            if ch.is_ascii_lowercase() {
                ch.to_ascii_uppercase()
            } else {
                ch.to_ascii_lowercase()
            }
        })
        .collect::<String>();
    println!("{}", ans);
}
