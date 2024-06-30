#[allow(unused_imports)]
use proconio::{fastout, input, marker::Chars};

fn main() {
    input! {
      s: String,
      t: String,
    }

    let mut ans = false;

    for w in 1..s.len() {
        let mut words: Vec<String> = Vec::new();

        for j in 0..=(s.len() / w) {
            let left = w * j;
            let right = w * (j + 1);

            let slice = if right < s.len() {
                &s[left..right]
            } else {
                &s[left..]
            };

            if slice.len() != 0 {
                words.push(slice.to_string());
            }
        }

        for i in 0..100 {
            let mut res = String::new();
            for word in &words {
                let ch = match word.chars().nth(i) {
                    Some(ch) => ch,
                    None => break,
                };
                res.push(ch);
            }

            if res == t {
                ans = true;
            }
        }
    }

    if ans {
        println!("Yes");
    } else {
        println!("No");
    }
}
