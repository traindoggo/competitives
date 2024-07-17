#[allow(unused_imports)]
use proconio::{
    fastout, input,
    marker::{Chars, Usize1},
};

fn main() {
    input! {
      n: usize,
      ai: [i32; 2 * n],
    }

    let mut ans = 0;

    for i in 0..(2 * n - 2) {
        // println!("{} {}", ai[i], ai[i + 2]);
        if ai[i] == ai[i + 2] {
            ans += 1;
        }
    }

    println!("{}", ans);
}
