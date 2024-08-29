#include <vector>
#include <unordered_map>
#include <functional>

using namespace std;

struct VectorHash {
    size_t operator()(const vector<int>& v) const {
        size_t seed = 0;
        for (int num : v) {
            seed ^= hash<int>()(num) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<vector<int>, int, VectorHash> rowMap;

        for (int i = 0; i < n; ++i) {
            rowMap[grid[i]]++;
        }

        int count = 0;
        for (int j = 0; j < n; ++j) {
            vector<int> column(n);
            for (int i = 0; i < n; ++i) {
                column[i] = grid[i][j];
            }
            count += rowMap[column];
        }

        return count;
    }
};
