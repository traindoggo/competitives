#[allow(unused_imports)]
use proconio::{
    fastout, input,
    marker::{Chars, Usize1},
};

fn main() {
    input! {
      n: usize,
      ai: [usize; n],
      wi: [i64; n],
    }

    let mut boxes = vec![vec![0; 0]; n];

    for i in 0..n {
        let idx = ai[i] - 1;
        let w = wi[i];
        boxes[idx].push(w);
    }

    let mut total: i64 = 0;

    for b in boxes {
        if b.len() >= 2 {
            total += b.iter().sum::<i64>();
            total -= b.iter().max().unwrap();
        }
    }

    println!("{}", total);
}
