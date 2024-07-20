#[allow(unused)]
use proconio::{input, marker::Chars};

fn main() {
    input! {
        nums: [i32; 6],
    }

    let mut ans: Vec<i32> = vec![];

    let chess_piece = vec![1, 1, 2, 2, 2, 8];
    for (idx, num) in nums.iter().enumerate() {
        ans.push(chess_piece[idx] - num);
    }

    println!(
        "{}",
        ans.iter()
            .map(|num| num.to_string())
            .collect::<Vec<_>>()
            .join(" ")
    )
}
