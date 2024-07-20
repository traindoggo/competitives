use std::io::{stdout, BufWriter, Write};

#[allow(unused)]
use proconio::{input, marker::Chars};

fn main() {
    input! {
        n: i32,
    }

    let out = stdout();
    let mut out = BufWriter::new(out.lock());

    for i in 1..=n {
        out.write(format!("{}\n", i).as_bytes()).unwrap();
    }
}
