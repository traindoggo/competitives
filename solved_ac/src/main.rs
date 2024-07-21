#[allow(unused)]
use proconio::{input, marker::Chars};

fn main() {
    input! {
        t: usize,
        nums: [(i32, i32, i32); t],
    }

    for (h, _, n) in nums {
        let (height, room) = if n % h == 0 {
            (h, n / h)
        } else {
            (n % h, n / h + 1)
        };

        let ans = height * 100 + room;
        println!("{}", ans);
    }
}
