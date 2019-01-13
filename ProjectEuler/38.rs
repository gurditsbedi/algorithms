fn num_len(mut num: i32) -> i32 {
    let mut count = 0;
    while num != 0 {
        num /= 10;
        count += 1;
    }
    count
}

fn is_pandigital(mut num: i32) -> bool {
    let mut tendigits: [i32; 10] = [0; 10];
    while num != 0 {
        tendigits[(num%10) as usize] = 1;
        num /= 10;
    }
    tendigits.iter().skip(1).all(|&x| x == 1)
}


fn num_concate(na: i32, nb: i32) -> i32 {
    na * 10_i32.pow(num_len(nb) as u32) + nb
}


fn main() {
    assert!(!is_pandigital(23456789));
    assert!(!is_pandigital(33456789));
    assert!(is_pandigital(123456789));
    assert!(is_pandigital(918273645));
    assert!(is_pandigital(192384576));

    assert_eq!(num_concate(123, 476), 123476);
    assert_eq!(num_concate(0, 476), 476);

    let limit: u32 = 9999;
    let mut maxconcatnum: i32 = i32::min_value();

    for i in 1..limit {
        let mut concatnum = 0;
        let mut m = 1;

        while num_len(concatnum) < 9 {
            if num_len(concatnum) + num_len((i * m) as i32) > 9 {
                break;
            }
            concatnum = num_concate(concatnum, (i * m) as i32);


            m += 1;

        }
        if is_pandigital(concatnum) {
            //println!("{} -> {}", i, concatnum);
            maxconcatnum = if concatnum > maxconcatnum { concatnum } else { maxconcatnum }
        }


    }
    println!("{}", maxconcatnum);
}
