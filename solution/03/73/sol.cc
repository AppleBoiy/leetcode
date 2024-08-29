class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        if (nums1.empty() || nums2.empty()) {
            return result;
        }
        auto cmp = [&nums1, &nums2](const pair<int, int>& a, const pair<int, int>& b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        pq.push({0, 0});
        while (k-- > 0 && !pq.empty()) {
            auto [i, j] = pq.top();
            pq.pop();
            result.push_back({nums1[i], nums2[j]});
            if (i + 1 < nums1.size()) {
                pq.push({i + 1, j});
            }
            if (i == 0 && j + 1 < nums2.size()) {
                pq.push({i, j + 1});
            }
        }
        return result;
    }
};