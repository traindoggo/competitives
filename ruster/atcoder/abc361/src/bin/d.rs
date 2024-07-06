#[allow(unused_imports)]
use proconio::{
    fastout, input,
    marker::{Chars, Usize1},
};

fn main() {
    input! {
      n: usize,
      s: Chars,
      t: Chars,
    }

    if !valid_stone(&s, &t) {
        println!("-1");
        return;
    }

    println!("{:?}", s);
    println!("{:?}", t);
}

fn valid_stone(s: &Vec<char>, t: &Vec<char>) -> bool {
    let mut white = 0;
    let mut black = 0;

    for &ch in s {
        if ch == 'W' {
            white += 1;
        }

        if ch == 'B' {
            black += 1;
        }
    }

    for &ch in t {
        if ch == 'W' {
            white -= 1;
        }

        if ch == 'B' {
            black -= 1;
        }
    }

    // println!("valid stone: {} {}", white, black);

    white == 0 && black == 0
}
