use std::collections::HashSet;

fn gcd(a: u32, b: u32) -> u32 {
    if b == 0 {
        return a;
    }
    gcd(b, a % b)
}

fn main() {
    let limit: u32 = 12000;

    let mut set: HashSet<(u32, u32)> = HashSet::new();

    let ub: f32 = 1.0 / 2.0;
    let lb: f32 = 1.0 / 3.0;

    for d in 1..=limit {
        for n in d / 3..=d {
            let num: f32 = n as f32 / d as f32;

            //println!("num: {:2} {:2} {}", n, d, num);

            if num > ub {
                break;
            }

            if lb < num && num < ub {
                let gcdnd = gcd(n, d);
                if gcdnd == 1 {
                    set.insert((n, d));
                }
            }
        }
    }

    //println!("{:?}", set);
    println!("{}", set.len());
}
