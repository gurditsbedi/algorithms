fn penta(x: i32) -> i32 {
    x * (3 * x - 1) / 2
}


fn is_penta(x: u32) -> bool {
    let t: f32 = (((24 * x + 1) as f32).sqrt() + 1.0) / 6.0;
    t.ceil() == t.floor()
}


fn main() {

    assert!(is_penta(1));
    assert!(is_penta(12));
    assert!(is_penta(35));
    assert!(is_penta(70));
    assert!(is_penta(117));


    let mut i = 1;

    let result = 'outer: loop {
        i += 1;
        let x = penta(i);

        for y in (1..i-1).rev() {
            //println!("{}", y);
            let mut y = penta(y);

            let summ = (x + y) as u32;
            let diff = (x-y).abs() as u32;


            //println!("{} {} {} {}",x, y, summ, diff);

            if is_penta(summ) && is_penta(diff) {
                break 'outer diff;
            }
        }
    };

    println!("{}", result);
}
