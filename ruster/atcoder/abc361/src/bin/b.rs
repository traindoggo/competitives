#[allow(unused_imports)]
use proconio::{
    fastout, input,
    marker::{Chars, Usize1},
};

fn main() {
    input! {
      a: i32,
      b: i32,
      c: i32,
      d: i32,
      e: i32,
      f: i32,

      g: i32,
      h: i32,
      i: i32,
      j: i32,
      k: i32,
      l: i32,
    }

    if check(a, b, c, d, e, f, g, h, i, j, k, l) {
        println!("Yes");
    } else {
        println!("No");
    }
}

fn check(
    a: i32,
    b: i32,
    c: i32,
    d: i32,
    e: i32,
    f: i32,

    g: i32,
    h: i32,
    i: i32,
    j: i32,
    k: i32,
    l: i32,
) -> bool {
    // x
    if a >= j {
        return false;
    }

    if d <= g {
        return false;
    }

    // y
    if b >= k {
        return false;
    }

    if e <= h {
        return false;
    }

    // z
    if c >= l {
        return false;
    }

    if f <= i {
        return false;
    }

    return true;
}
