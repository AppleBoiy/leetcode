#include <bits/stdc++.h>
#include "sol.cc"

using namespace std;


int main() {
    vector nums = {2, 4, 1, 3, 5};
    constexpr int k = 1;
    constexpr int multiplier = 2;
    const vector<int> result = Solution::getFinalState(nums, k, multiplier);
    for (const int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}