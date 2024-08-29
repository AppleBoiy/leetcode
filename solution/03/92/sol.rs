impl Solution {
    pub fn is_subsequence(s: String, t: String) -> bool {
        let mut s = s.chars();
        let mut current = s.next();

        for c in t.chars() {
            if let Some(ch) = current {
                if ch == c {
                    current = s.next();
                }
            } else {
                break;
            }
        }

        current.is_none()
    }
}
