#![allow(dead_code)]

use std::collections::HashMap;

struct Solution;

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut char_map = HashMap::new();
        let mut max_length = 0;
        let mut start = 0;

        for (i, c) in s.chars().enumerate() {
            if let Some(&index) = char_map.get(&c) {
                start = start.max(index + 1);
            }
            char_map.insert(c, i);
            max_length = max_length.max(i - start + 1);
        }

        max_length as i32
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_1() {
        let s = "abcabcbb".to_string();
        assert_eq!(Solution::length_of_longest_substring(s), 3);
    }

    #[test]
    fn test_2() {
        let s = "bbbbb".to_string();
        assert_eq!(Solution::length_of_longest_substring(s), 1);
    }

    #[test]
    fn test_3() {
        let s = "pwwkew".to_string();
        assert_eq!(Solution::length_of_longest_substring(s), 3);
    }

    #[test]
    fn test_4() {
        let s = "".to_string();
        assert_eq!(Solution::length_of_longest_substring(s), 0);
    }
}

fn main() {
    let s = "abcabcbb".to_string();
    let result = Solution::length_of_longest_substring(s);
    println!("{}", result);
}