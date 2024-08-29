impl Solution {
    pub fn max_distance(arrays: Vec<Vec<i32>>) -> i32 {
        let mut min = arrays[0][0];
        let mut max = arrays[0][arrays[0].len() - 1];
        let mut res = 0;
        for i in 1..arrays.len() {
            res = res.max((arrays[i][arrays[i].len() - 1] - min).abs());
            res = res.max((max - arrays[i][0]).abs());
            min = min.min(arrays[i][0]);
            max = max.max(arrays[i][arrays[i].len() - 1]);
        }
        res
    }
}