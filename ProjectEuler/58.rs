fn is_prime(num: u32) -> bool {
    if num <= 1 {
        return false;
    }
    if num <= 3 {
        return true;
    }

    if num % 2 == 0 || num % 3 == 0 {
        return false;
    }

    let mut i: u32 = 5;
    while i * i <= num {
        if num % i == 0 || num % (i + 2) == 0 {
            return false;
        }
        i += 6;
    }

    return true;
}

fn corner_primes(l: u32, d: u32) -> u32 {
    /*
     * l : last term of the 4 number
     * d : common difference
     * return : number of primes
     */
    (1..4).filter(|i| is_prime(l - i * d)).count() as u32
}

fn main() {
    let mut count = 0;
    let mut i: u32 = 1;

    let result: u32 = loop {
        let l: u32 = (2 * (i + 1) - 1).pow(2);

        count += corner_primes(l, i * 2);

        let curr_ratio: f32 = count as f32 / (4.0 * i as f32 + 1.0) * 100.0;

        if curr_ratio < 10.0 {
            break 2 * i + 1;
        }
        i += 1;
    };
    println!("{}", result);
}
