#![allow(unused_mut)]

// 3266. Final Array State After K Multiplication Operations II
// error: TLE

use std::cmp::Reverse;
use std::collections::BinaryHeap;

const MOD: i64 = 10i64.pow(9) + 7;

struct Solution;

impl Solution {
    pub fn get_final_state(mut nums: Vec<i32>, k: i32, mul: i32) -> Vec<i32> {
        if mul == 1 {
            return nums;
        }

        let n = nums.len();
        let mut heap: BinaryHeap<Reverse<(i64, usize)>> = BinaryHeap::new();

        for (i, &x) in nums.iter().enumerate() {
            heap.push(Reverse((x as i64, i)));
        }

        let mul = mul as i64;
        let mut count = vec![0; n];
        let mut k = k as i64;

        while k > 0 && !heap.is_empty() {
            k -= 1;
            let Reverse((val, idx)) = heap.pop().unwrap();
            count[idx] += 1;
            let new_val = (val * mul) % MOD;
            heap.push(Reverse((new_val, idx)));
        }

        let mut final_counts = vec![0; n];
        let mut heap_vec: Vec<(i64, usize)> = heap.into_sorted_vec().into_iter().map(|Reverse(x)| x).collect();

        for (i, (_val, idx)) in heap_vec.iter().enumerate() {
            final_counts[*idx] += count[*idx] + (if i < (k % n as i64) as usize { 1 } else { 0 });
        }

        for (i, c) in final_counts.iter().enumerate() {
            nums[i] = ((nums[i] as i64 * pow(mul, *c)) % MOD) as i32;
        }

        nums
    }
}

fn pow(mut x: i64, mut y: i64) -> i64 {
    let mut res = 1;
    while y > 0 {
        if y % 2 == 1 {
            res = (res * x) % MOD;
        }
        x = (x * x) % MOD;
        y /= 2;
    }
    res
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_1() {
        let nums = vec![2, 1, 3, 5, 6];
        let k = 5;
        let mul = 2;
        let res = Solution::get_final_state(nums, k, mul);
        assert_eq!(res, vec![8, 4, 6, 5, 6]);
    }

    #[test]
    fn test_2() {
        let nums = vec![689009555, 813837455, 240010825, 967305450];
        let k = 804709161;
        let mul = 601392;
        let res = Solution::get_final_state(nums, k, mul);
        assert_eq!(res, vec![158205367, 862774837, 475528263, 828321106]);
    }
}

fn main() {
    let nums = vec![2, 1, 3, 5, 6];
    let k = 5;
    let mul = 2;
    let res = Solution::get_final_state(nums, k, mul);
    println!("{:?}", res);
}