struct Solution;

impl Solution {
    pub fn my_atoi(s: String) -> i32 {
        let mut s = s.trim_start();
        let mut sign = 1;
        if s.starts_with('-') {
            sign = -1;
            s = &s[1..];
        } else if s.starts_with('+') {
            s = &s[1..];
        }

        let mut num: i32 = 0;
        for c in s.chars() {
            if let Some(d) = c.to_digit(10) {
                let digit = d as i32;
                if num > (i32::MAX - digit) / 10 {
                    return if sign == 1 { i32::MAX } else { i32::MIN };
                }
                num = num * 10 + digit;
            } else {
                break;
            }
        }

        num * sign
    }
}

fn main() {
    assert_eq!(Solution::my_atoi("42".to_string()), 42);
    assert_eq!(Solution::my_atoi("   -42".to_string()), -42);
    assert_eq!(Solution::my_atoi("4193 with words".to_string()), 4193);
    assert_eq!(Solution::my_atoi("words and 987".to_string()), 0);
    assert_eq!(Solution::my_atoi("-91283472332".to_string()), -2147483648);
    assert_eq!(Solution::my_atoi("91283472332".to_string()), 2147483647);
    assert_eq!(Solution::my_atoi("+-12".to_string()), 0);
    assert_eq!(Solution::my_atoi("00000-42a1234".to_string()), 0);
    assert_eq!(Solution::my_atoi("21474836460".to_string()), 2147483647);
    assert_eq!(Solution::my_atoi("2147483648".to_string()), 2147483647);
    assert_eq!(Solution::my_atoi("-2147483649".to_string()), -2147483648);
    assert_eq!(Solution::my_atoi("2147483647".to_string()), 2147483647);
    assert_eq!(Solution::my_atoi("-2147483648".to_string()), -2147483648);
    assert_eq!(Solution::my_atoi("2147483646".to_string()), 2147483646);
    assert_eq!(Solution::my_atoi("-2147483647".to_string()), -2147483647);
    assert_eq!(Solution::my_atoi("2147483647".to_string()), 2147483647);
    assert_eq!(Solution::my_atoi("-2147483648".to_string()), -2147483648);
    assert_eq!(Solution::my_atoi("2147483648".to_string()), 2147483647);
    assert_eq!(Solution::my_atoi("-2147483649".to_string()), -2147483648);
    assert_eq!(Solution::my_atoi("21474836460".to_string()), 2147483647);
    assert_eq!(Solution::my_atoi("2147483648".to_string()), 2147483647);
}