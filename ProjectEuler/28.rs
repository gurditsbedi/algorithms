fn one_shot_answer(x: u32) -> u32 {
    (16 * x.pow(3) + 30 * x.pow(2) + 26 * x.pow(1) + 3) / 3
}

fn sum_of_each_square_corner(l: u32, d: u32) -> u32 {
    /*
     * l : last term of the 4 number
     * d : common difference
     */
    4 * l - 6 * d
}

fn main() {
    let size: u32 = 5;
    let layers: u32 = size / 2;

    let mut sum = 1;

    for i in 1..=layers {
        let l: u32 = (2 * (i + 1) - 1).pow(2);
        sum += sum_of_each_square_corner(l, i * 2);
    }

    println!("{}", sum);
    //println!("{}", one_shot_answer(layers));
}
