#[allow(unused_imports)]
use proconio::{
    fastout, input,
    marker::{Chars, Usize1},
};

fn main() {
    input! {
      s: Chars,
    }

    let mut rice: i32 = -1;
    let mut silu: i32 = -1;

    for i in 0..s.len() {
        if s[i] == 'R' {
            rice = i as i32;
        }
        if s[i] == 'M' {
            silu = i as i32;
        }
    }

    if rice < silu {
        println!("Yes");
    } else {
        println!("No");
    }
}
