#[allow(unused_imports)]
use proconio::{
    fastout, input,
    marker::{Chars, Usize1},
};

fn main() {
    input! {
      n: usize,
      ai: [(i32, i32); n],
    }

    eprint!("{:?}", ai);
}
