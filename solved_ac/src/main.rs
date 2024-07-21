use std::collections::HashSet;

#[allow(unused)]
use proconio::{input, marker::Chars};

fn main() {
    input! {
        nums: [i32; 10],
    }
    eprintln!("{:?}", nums);

    let mut st: HashSet<i32> = HashSet::new();

    for num in nums {
        st.insert(num % 42);
    }

    println!("{}", st.len());
}
