static const auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
private:
    char vowels[5] = {'a', 'e', 'i', 'o', 'u'};

    bool isVowel(char c) {
        c = tolower(c);
        for (char v : vowels) {
            if (c == v) {
                return true;
            }
        }
        return false;
    }
public:
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (!isVowel(s[i])) {
                i++;
            } else if (!isVowel(s[j])) {
                j--;
            } else {
                swap(s[i++], s[j--]);
            }
        }
        return s;
    }
};