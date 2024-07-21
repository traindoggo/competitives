#[allow(unused)]
use proconio::{input, marker::Chars};

fn main() {
    input! {
        a: String,
        b: String,
        c: String,
    }

    add1(&a, &b, &c);
    add2(&a, &b, &c);
}

fn add1(a: &String, b: &String, c: &String) {
    let mut sum: i32 = 0;
    sum += a.parse::<i32>().unwrap();
    sum += b.parse::<i32>().unwrap();
    sum -= c.parse::<i32>().unwrap();
    println!("{}", sum);
}

fn add2(a: &String, b: &String, c: &String) {
    let mut k = String::new();
    k.push_str(a);
    k.push_str(b);

    let mut sum: i32 = 0;
    sum += k.parse::<i32>().unwrap();
    sum -= c.parse::<i32>().unwrap();
    println!("{}", sum);
}
