#include <bits/stdc++.h>

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> s2c;
        unordered_map<char, string> c2s;
        istringstream in(s);
        int i = 0;
        for (string word; in >> word; i++) {
            if (i == pattern.size()) return false;

            if (s2c.count(word) && s2c[word] != pattern[i]) return false;
            if (c2s.count(pattern[i]) && c2s[pattern[i]] != word) return false;

            s2c[word] = pattern[i];
            c2s[pattern[i]] = word;
        }
        return i == pattern.size();
    }
};
