class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int i = 0;

        while (i < words.size()) {
            int j = i, len = 0;
            while (j < words.size() && len + words[j].size() + j - i <= maxWidth) {
                len += words[j++].size();
            }

            int spaces = maxWidth - len;
            int slots = j - i - 1;
            string line;

            if (j == words.size() || slots == 0) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) line += " ";
                }
                int remainingSpaces = maxWidth - line.size();
                for (int l = 0; l < remainingSpaces; l++) {
                    line += " ";
                }
            } else {
                int evenSpaces = spaces / slots;
                int extraSpaces = spaces % slots;
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) {
                        for (int l = 0; l < evenSpaces + (k - i < extraSpaces ? 1 : 0); l++) {
                            line += " ";
                        }
                    }
                }
            }

            res.push_back(line);
            i = j;
        }

        return res;
    }
};