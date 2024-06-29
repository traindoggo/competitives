#[allow(unused_imports)]
use proconio::{
    fastout, input,
    marker::{Chars, Usize1},
};

fn main() {
    input! {
      a: u32,
      b: u32,
    }

    let ans = a.pow(b) + b.pow(a);
    println!("{}", ans);
}
