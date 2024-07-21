#[allow(unused)]
use proconio::{input, marker::Chars};

fn main() {
    input! {
        h:i32,
        m:i32,
    }

    let mut total: i32 = h * 60 + m;
    eprintln!("{}", total);

    total -= 45;
    total += 24 * 60;
    total %= 24 * 60;

    let h = total / 60;
    total %= 60;
    let m = total;
    println!("{} {}", h, m);
}
