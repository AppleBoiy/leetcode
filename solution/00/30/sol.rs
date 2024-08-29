struct Solution;

impl Solution {
    pub fn find_substring(s: String, words: Vec<String>) -> Vec<i32> {
        let mut res = Vec::new();
        if words.is_empty() {
            return res;
        }
        let n = s.len();
        let m = words.len();
        let len = words[0].len();
        let mut map = std::collections::HashMap::new();
        for word in words.iter() {
            *map.entry(word).or_insert(0) += 1;
        }
        for i in 0..len {
            let mut left = i;
            let mut right = i;
            let mut count = 0;
            let mut window = std::collections::HashMap::new();
            while right + len <= n {
                let word = s[right..right + len].to_string();
                right += len;
                if !map.contains_key(&word) {
                    count = 0;
                    left = right;
                    window.clear();
                } else {
                    *window.entry(word.clone()).or_insert(0) += 1;
                    count += 1;
                    while window.get(&word).unwrap() > map.get(&word).unwrap() {
                        let word = s[left..left + len].to_string();
                        left += len;
                        *window.get_mut(&word).unwrap() -= 1;
                        count -= 1;
                    }
                    if count == m {
                        res.push(left as i32);
                    }
                }
            }
        }
        res
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_1() {
        let s = "barfoothefoobarman".to_string();
        let words = vec!["foo".to_string(), "bar".to_string()];
        let res = vec![0, 9];
        assert_eq!(Solution::find_substring(s, words), res);
    }

    #[test]
    fn test_2() {
        let s = "wordgoodgoodgoodbestword".to_string();
        let words = vec!["word".to_string(), "good".to_string(), "best".to_string(), "word".to_string()];
        let res = Vec::new();
        assert_eq!(Solution::find_substring(s, words), res);
    }
}

fn main() {
    let s = "barfoothefoobarman".to_string();
    let words = vec!["foo".to_string(), "bar".to_string()];
    println!("{:?}", Solution::find_substring(s, words));
}