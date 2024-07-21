#[allow(unused)]
use proconio::{input, marker::Chars};

fn main() {
    input! {
        t: usize,
        si: [(i32, Chars); t],
    }

    for (n, s) in si {
        let mut ans = String::new();

        for ch in s {
            for _ in 0..n {
                ans.push(ch);
            }
        }

        println!("{}", ans);
    }
}
