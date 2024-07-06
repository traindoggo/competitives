#[allow(unused_imports)]
use proconio::{
    fastout, input,
    marker::{Chars, Usize1},
};

fn main() {
    input! {
      n: usize,
      k: usize,
      mut ai: [i32;n],
    }

    ai.sort();

    let mut minv: i32 = 1 << 30;

    let range = n - k;
    for i in 0..k + 1 {
        //println!("{} {}", ai[i], ai[i + range - 1]);
        let cur = ai[i + range - 1] - ai[i];
        minv = minv.min(cur);
    }

    for range in ai.windows(n - k) {
        println!("{:?}", range);
    }

    println!("{}", minv);
}
