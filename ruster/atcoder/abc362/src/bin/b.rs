#[allow(unused_imports)]
use proconio::{
    fastout, input,
    marker::{Chars, Usize1},
};

fn dist(pa: (f32, f32), pb: (f32, f32)) -> f32 {
    let x = pa.0 - pb.0;
    let y = pa.1 - pb.1;
    x * x + y * y
}

fn main() {
    input! {
        ps: [(f32, f32); 3],
    }

    eprintln!("{:?}", ps);


    let mut ans = false;
    for i in 0..3 {
        let x = dist(ps[i % 3], ps[(i + 1) % 3]);
        let y = dist(ps[(i + 1) % 3], ps[(i + 2) % 3]);
        let z = dist(ps[(i + 2) % 3], ps[(i + 3) % 3]);


        ans |= x + y == z;
    }

    println!("{}", if ans { "Yes" } else { "No" });
}
