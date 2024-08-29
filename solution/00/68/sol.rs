impl Solution {
    pub fn full_justify(words: Vec<String>, max_width: i32) -> Vec<String> {
        let mut res = Vec::new();
        let mut i = 0;
        while i < words.len() {
            let mut j = i + 1;
            let mut len = words[i].len();
            while j < words.len() && len + words[j].len() + j - i <= max_width as usize {
                len += words[j].len();
                j += 1;
            }
            let mut line = words[i].clone();
            let mut space = j - i - 1;
            if j == words.len() || j - i == 1 {
                for k in i + 1..j {
                    line.push(' ');
                    line += &words[k];
                }
                while line.len() < max_width as usize {
                    line.push(' ');
                }
            } else {
                let mut extra = (max_width as usize - len) / space;
                let mut remain = (max_width as usize - len) % space;
                for k in i + 1..j {
                    for _ in 0..extra {
                        line.push(' ');
                    }
                    if remain > 0 {
                        line.push(' ');
                        remain -= 1;
                    }
                    line += &words[k];
                }
            }
            res.push(line);
            i = j;
        }
        res
    }
}