#[allow(unused)]
use proconio::{input, marker::Chars};

fn main() {
    input! {
        n: usize,
        marks: [Chars;n],
    }

    for line in marks {
        let mut total: i32 = 0;
        let mut cnt: i32 = 0;

        for ch in line {
            if ch == 'O' {
                cnt += 1;
            } else {
                cnt = 0;
            }
            total += cnt;
        }
        println!("{}", total);
    }
}
