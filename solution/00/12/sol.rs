struct Solution;

impl Solution {
    pub fn int_to_roman(num: i32) -> String {
        let mut res = String::new();
        let mut num = num;
        let mut i = 0;
        let roman = vec![
            (1000, "M"),
            (900, "CM"),
            (500, "D"),
            (400, "CD"),
            (100, "C"),
            (90, "XC"),
            (50, "L"),
            (40, "XL"),
            (10, "X"),
            (9, "IX"),
            (5, "V"),
            (4, "IV"),
            (1, "I"),
        ];
        while num > 0 {
            while num >= roman[i].0 {
                res.push_str(roman[i].1);
                num -= roman[i].0;
            }
            i += 1;
        }
        res
    }
}

#[cfg(test)]
mod tests {
    use Solution;

    #[test]
    fn test_1() {
        assert_eq!(Solution::int_to_roman(3), "III".to_string());
    }

    #[test]
    fn test_2() {
        assert_eq!(Solution::int_to_roman(4), "IV".to_string());
    }

    #[test]
    fn test_3() {
        assert_eq!(Solution::int_to_roman(9), "IX".to_string());
    }

    #[test]
    fn test_4() {
        assert_eq!(Solution::int_to_roman(58), "LVIII".to_string());
    }

    #[test]
    fn test_5() {
        assert_eq!(Solution::int_to_roman(1994), "MCMXCIV".to_string());
    }
}

fn main() {
    println!("int_to_roman(3)={}", Solution::int_to_roman(3));
}