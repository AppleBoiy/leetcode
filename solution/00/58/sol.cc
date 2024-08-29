class Solution {
public:
    int lengthOfLastWord(string s) {
        int result = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ' ') {
                if (result > 0) {
                    break;
                }
            } else {
                result++;
            }
        }
        return result;
    }
};
