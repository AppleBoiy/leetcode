class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max_candy = *max_element(candies.begin(), candies.end());
        vector<bool> res;
        for (int i = 0; i < candies.size(); ++i) {
            res.push_back(candies[i] + extraCandies >= max_candy);
        }
        return res;
    }
};