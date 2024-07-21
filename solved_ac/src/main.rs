#[allow(unused)]
use proconio::{input, marker::Chars};

fn main() {
    input! {
        s: Chars,
    }

    let mut v: Vec<i32> = vec![-1; 26];

    for (idx, &ch) in s.iter().enumerate() {
        let i = (ch as u8 - 'a' as u8) as usize;

        if v[i] == -1 {
            v[i] = idx as i32;
        }
    }

    print(v);
}

fn print(v: Vec<i32>) {
    println!(
        "{}",
        v.iter()
            .map(|ch| ch.to_string())
            .collect::<Vec<_>>()
            .join(" ")
    );
}
