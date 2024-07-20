#[allow(unused)]
use std::io::{self, BufReader};

#[allow(unused)]
use proconio::{input, marker::Chars, source::line::LineSource};

fn main() {
    //let mut stdin = LineSource::new(BufReader::new(io::stdin()));
    //macro_rules! input(($($tt:tt)*) => (proconio::input!(from &mut stdin, $($tt)*)));
    let mut teams: Vec<(usize, usize)> = Vec::new();
    teams.push((12, 1600));
    teams.push((11, 894));
    teams.push((11, 1327));
    teams.push((10, 1311));
    teams.push((9, 1004));
    teams.push((9, 1178));
    teams.push((9, 1357));
    teams.push((8, 837));
    teams.push((7, 1055));
    teams.push((6, 556));
    teams.push((6, 773));

    input! {
        idx: usize,
    }
    let team = teams[idx - 1];
    println!("{} {}", team.0, team.1);
}
