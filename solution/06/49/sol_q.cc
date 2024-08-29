static const auto __ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> q1, q2;
        int n = senate.size();
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') {
                q1.push(i);
            } else {
                q2.push(i);
            }
        }
        while (!q1.empty() && !q2.empty()) {
            int r_index = q1.front();
            q1.pop();
            int d_index = q2.front();
            q2.pop();
            if (r_index < d_index) {
                q1.push(r_index + n);
            } else {
                q2.push(d_index + n);
            }
        }
        return q1.size() > q2.size() ? "Radiant" : "Dire";
    }
};