#[allow(unused)]
use proconio::{input, marker::Chars};

fn main() {
    input! {
        n: usize,
        x: i32,
        nums: [i32; n],
    }

    let mut ans: Vec<i32> = Vec::new();
    for num in nums {
        if num < x {
            ans.push(num);
        }
    }

    println!(
        "{}",
        ans.iter()
            .map(|n| n.to_string())
            .collect::<Vec<_>>()
            .join(" ")
    );
}
