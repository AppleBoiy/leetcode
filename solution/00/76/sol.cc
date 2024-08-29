class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> count(128, 0);
        for (char c : t) {
            count[c]++;
        }

        int left = 0;
        int right = 0;
        int min_len = INT_MAX;
        int min_left = 0;
        int count_t = t.size();

        while (right < s.size()) {
            if (count[s[right]] > 0) {
                count_t--;
            }
            count[s[right]]--;
            right++;

            while (count_t == 0) {
                if (right - left < min_len) {
                    min_len = right - left;
                    min_left = left;
                }

                if (count[s[left]] == 0) {
                    count_t++;
                }
                count[s[left]]++;
                left++;
            }
        }

        return min_len == INT_MAX ? "" : s.substr(min_left, min_len);
    }
};