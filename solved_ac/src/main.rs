#[allow(unused)]
use proconio::{input, marker::Chars};

fn main() {
    input! {
        nums: [i32; 9],
    }

    let mut mx: i32 = 0;
    let mut idx: usize = 0;

    for i in 0..nums.len() {
        if mx < nums[i] {
            mx = nums[i];
            idx = i;
        }
    }

    println!("{}", mx);
    println!("{}", idx + 1);
}
