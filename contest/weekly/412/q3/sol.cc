#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;


class Solution
{
public:
    static ll power(ll x, ll y)
    {
        ll result = 1;
        while (y)
        {
            if (y & 1)
            {
                result = result * x % MOD;
            }
            y >>= 1;
            x = x * x % MOD;
        }
        return result;
    }

    static vector<int> getFinalState(vector<int>& nums, int k, const int multiplier)
    {
        if (multiplier == 1)
        {
            return nums;
        }
        priority_queue<pll, vector<pll>, greater<>> pq;
        const auto n = nums.size();
        for (int i = 0; i < n; i++) pq.emplace(nums[i], i);

        unordered_map<ll, ll> cnt, opt;
        do
        {
            auto x = pq.top().first, i = pq.top().second;
            pq.pop();
            x *= multiplier;
            pq.emplace(x, i);
            opt[i]++;
            k--;
        }
        while (k > 0 && opt.size() != n);

        vector<ll> tmp(n);
        while (!pq.empty())
        {
            const auto x = pq.top().first, y = pq.top().second;
            pq.pop();
            tmp[y] = x;
        }

        const auto dec = k / n;
        auto frac = k % n;
        for (int i = 0; i < n; i++) pq.emplace(tmp[i], i);

        while (!pq.empty())
        {
            const auto x = pq.top().second;
            cnt[x] = static_cast<int>(dec);
            if (frac > 0)
            {
                cnt[x]++;
                frac--;
            }
            pq.pop();
        }


        for (int i = 0; i < n; i++)
        {
            const auto mlt = power(multiplier, cnt[i]);
            tmp[i] = tmp[i] % MOD * mlt % MOD % MOD;
            nums[i] = static_cast<int>(tmp[i]);
        }
        return nums;
    }
};

int main()
{
    vector nums = {1, 1, 1, 1, 1};
    constexpr int k = 10;
    constexpr int multiplier = 2;
    const auto res = Solution::getFinalState(nums, k, multiplier);
    for (const auto& x : res) cout << x << " ";
    cout << endl;
    return 0;
}
