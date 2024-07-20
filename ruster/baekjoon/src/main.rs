#[allow(unused)]
use proconio::input;

fn main() {
    input! {
        a: f64,
        b: f64,
    }

    println!("{:.10}", a / b);
}
