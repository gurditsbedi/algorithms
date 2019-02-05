const INPUT: &'static str = include_str!("./p059_cipher.txt");

fn xor_vector(key: [u8; 3], input: Vec<u8>) -> Result<Vec<u8>, &'static str> {
    let mut afterxor: Vec<u8> = Vec::new();

    for (idx, n) in input.iter().enumerate() {
        let value: u8 = n ^ key[idx % 3];
        if value > 122 {
            return Err("character out of required range");
        }
        afterxor.push(value);
    }

    return Ok(afterxor);
}

fn main() {
    let input: Vec<u8> = INPUT
        .trim_right()
        .split(',')
        .map(|x| x.parse::<u8>().unwrap())
        .collect();

    let common_words: [&str; 4] = ["in", "the", "and", "to"];

    for i in 97..=122 {
        for j in 97..=122 {
            for k in 97..=122 {
                let key: [u8; 3] = [i, j, k];

                let afterxor = xor_vector(key, input.clone());

                if let Ok(xor_data) = afterxor {
                    let text: String = xor_data.iter().map(|&x| x as char).collect();
                    let common_words_exists = common_words.iter().all(|&x| !text.find(x).is_none());

                    if common_words_exists {
                        // If you want to know what the text is uncomment below line.
                        //println!("{}", text);

                        let mut result: u32 =
                            xor_data.iter().fold(0 as u32, |acc, x| acc + (*x as u32));
                        println!("{}", result);
                    }
                }
            }
        }
    }
}
