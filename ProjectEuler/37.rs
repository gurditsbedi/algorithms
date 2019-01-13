fn is_prime(num: i32) -> bool {

    if num <= 1 {
        return false;
    }
    if num <= 3 {
        return true;
    }

    if num % 2 == 0 || num % 3 == 0 {
        return false
    }

    let mut i:i32 = 5;
    while i * i <= num  {
        if num % i == 0 || num % (i + 2) == 0 {
            return false
        }
        i += 6;
    }

    return true
}


fn num_len(mut num: i32) -> i32 {
    let mut count = 0;
    while num != 0 {
        num /= 10;
        count += 1;
    }
    count
}


fn num_slice(num: i32, a: i32, b: i32) -> Option<i32> {
    let n_len: i32 = num_len(num);
    if b <= n_len && a < b {
        Some(num / (10_i32).pow((num_len(num) - b) as u32) % (10_i32).pow((b-a) as u32))
    } else {
        None
    }
}


fn main() {
    let limit = 11;

    let mut sum = 0;
    let mut count = 0;

    let mut n = 10;
    while count < limit {

        let n_len = num_len(n);
        let n_is_prime = is_prime(n);
        let mut n_tpcount = 0;

        if !n_is_prime {
            n += 1;
            continue;
        }

        for i in 0..n_len-1 {
            let leftright = num_slice(n, i + 1, n_len).unwrap_or(0);
            let rightleft = num_slice(n, 0, n_len - i - 1).unwrap_or(0);

            if is_prime(leftright) && is_prime(rightleft) {
                n_tpcount += 1;
            } else {
                break;
            }
        }

        if n_tpcount == n_len - 1 {
            //println!("{} {}", count + 1, n);
            sum += n;
            count += 1;
        }

        n += 1;
    }

    println!("{}", sum);
}
