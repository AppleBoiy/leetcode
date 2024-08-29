#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cassert>

using namespace std;

class Solution
{
public:
    static vector<int> findSubstring(const string& s, const vector<string>& words)
    {
        vector<int> res;
        if (words.empty())
        {
            return res;
        }
        const int n = s.size(), m = words.size(), len = words[0].size();
        unordered_map<string, int> wordCount;
        for (const string& word : words)
        {
            wordCount[word]++;
        }
        for (int i = 0; i < len; i++)
        {
            int left = i, count = 0;
            unordered_map<string, int> window;
            for (int j = i; j <= n - len; j += len)
            {
                if (string word = s.substr(j, len); wordCount.count(word))
                {
                    window[word]++;
                    count++;
                    while (window[word] > wordCount[word])
                    {
                        window[s.substr(left, len)]--;
                        left += len;
                        count--;
                    }
                    if (count == m)
                    {
                        res.push_back(left);
                        window[s.substr(left, len)]--;
                        left += len;
                        count--;
                    }
                }
                else
                {
                    window.clear();
                    count = 0;
                    left = j + len;
                }
            }
        }
        return res;
    }
};

void testFindSubstring()
{
    Solution sol;

    string s1 = "barfoothefoobarman";
    vector<string> words1 = {"foo", "bar"};
    vector expected1 = {0, 9};
    assert(sol.findSubstring(s1, words1) == expected1);

    string s2 = "wordgoodgoodgoodbestword";
    vector<string> words2 = {"word", "good", "best", "word"};
    vector<int> expected2 = {};
    assert(sol.findSubstring(s2, words2) == expected2);

    string s3 = "barfoo";
    vector<string> words3 = {"foo", "bar", "baz"};
    vector<int> expected3 = {};
    assert(sol.findSubstring(s3, words3) == expected3);

    string s4 = "barfoofoobarthefoobarman";
    vector<string> words4 = {"bar", "foo", "the"};
    vector expected4 = {6, 9, 12};
    assert(sol.findSubstring(s4, words4) == expected4);

    cout << "All tests passed!" << endl;
}

int main()
{
    testFindSubstring();
    return 0;
}
