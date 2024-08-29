#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    static int countPairs(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        unordered_map<int, int> cnt;

        for (int x : nums) {
            unordered_set<int> vis = {x};
            string s = to_string(x);

            for (int j = 0; j < s.size(); ++j) {
                for (int i = 0; i < j; ++i) {
                    swap(s[i], s[j]);
                    vis.insert(stoi(s));
                    swap(s[i], s[j]);
                }
            }
            for (int v : vis) {
                ans += cnt[v];
            }
            cnt[x]++;
        }

        return ans;
    }
};