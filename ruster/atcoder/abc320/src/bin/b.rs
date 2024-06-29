#[allow(unused_imports)]
use proconio::{
    fastout, input,
    marker::{Chars, Usize1},
};

fn main() {
    input! {
      mut s: Chars,
    }

    let mut ans = 0;
    let len = s.len();

    for i in 0..len {
        for j in 1..=len - i {
            let col = &s[i..(i + j)];

            let mut is_palindrome = true;
            let size = col.len();

            for i in 0..size {
                if col[i] != col[size - i - 1] {
                    is_palindrome = false;
                }
            }

            if is_palindrome {
                ans = std::cmp::max(ans, size);
            }
        }
    }

    println!("{}", ans);
}
