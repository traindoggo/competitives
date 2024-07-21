#[allow(unused)]
use proconio::{input, marker::Chars};

fn main() {
    input! {
        si: [i32; 8],
    }

    let mut is_ascending = true;
    for i in 1..=8 {
        if si[i - 1] != i as i32 {
            is_ascending = false;
        }
    }

    if is_ascending {
        println!("ascending");
        return;
    }

    let mut is_descending = true;
    for i in 1..=8 {
        if si[i - 1] != 9 - i as i32 {
            is_descending = false;
        }
    }

    if is_descending {
        println!("descending");
        return;
    }

    println!("mixed");
}
