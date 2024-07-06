#[allow(unused_imports)]
use proconio::{
    fastout, input,
    marker::{Chars, Usize1},
};

fn main() {
    input! {
      n: usize,
      k: usize,
      x: i32,
      ai: [i32;n],
    }

    for i in 0..n {
        let a = ai[i];
        println!("{}", a);

        if i == k - 1 {
            println!("{}", x);
        }
    }
}
