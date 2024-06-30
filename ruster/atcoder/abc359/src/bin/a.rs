#[allow(unused_imports)]
use proconio::{
    fastout, input,
    marker::{Chars, Usize1},
};

fn main() {
    input! {
      n: usize,
      vs: [String; n],
    }

    let mut ans = 0;

    for name in vs {
        if name == "Takahashi" {
            ans += 1;
        }
    }

    println!("{}", ans);
}
