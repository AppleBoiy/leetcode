#![allow(unused_mut)]

use std::collections::{HashMap, HashSet};

pub struct Solution;

impl Solution {
    pub fn count_pairs(nums: Vec<i32>) -> i32 {
        let mut nums = nums;
        nums.sort();
        let mut ans = 0;
        let mut cnt = HashMap::new();

        for &x in nums.iter() {
            let mut vis = HashSet::new();
            let mut s: Vec<char> = x.to_string().chars().collect();

            vis.insert(x);

            let mut chars = s.clone();
            let len = chars.len();

            for j in 0..len {
                for i in 0..j {
                    chars.swap(i, j);
                    let num = chars
                        .iter()
                        .collect::<String>()
                        .parse::<i32>()
                        .unwrap();

                    vis.insert(num);
                    chars.swap(i, j);
                }
            }

            for v in vis {
                ans += cnt.get(&v).unwrap_or(&0);
            }

            *cnt.entry(x).or_insert(0) += 1;
        }

        ans
    }
}

fn main() {
    let nums = vec![123, 321, 231, 132, 213, 312];
    let result = Solution::count_pairs(nums);
    println!("Number of pairs: {}", result);
}
