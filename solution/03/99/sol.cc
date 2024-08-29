#include <unordered_map>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    unordered_map<string, unordered_map<string, double>> graph;

    bool dfs(const string& start, const string& end, double& value, unordered_set<string>& visited) {
        if (start == end) {
            return true;
        }
        visited.insert(start);
        for (auto& neighbor : graph[start]) {
            if (visited.find(neighbor.first) == visited.end()) {
                double current_value = value;
                value *= neighbor.second;
                if (dfs(neighbor.first, end, value, visited)) {
                    return true;
                }
                value = current_value;
            }
        }
        return false;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (int i = 0; i < equations.size(); ++i) {
            string u = equations[i][0];
            string v = equations[i][1];
            double value = values[i];
            graph[u][v] = value;
            graph[v][u] = 1.0 / value;
        }

        vector<double> results;
        for (auto& query : queries) {
            string u = query[0];
            string v = query[1];
            if (graph.find(u) == graph.end() || graph.find(v) == graph.end()) {
                results.push_back(-1.0);
            } else {
                unordered_set<string> visited;
                double value = 1.0;
                if (dfs(u, v, value, visited)) {
                    results.push_back(value);
                } else {
                    results.push_back(-1.0);
                }
            }
        }

        return results;
    }
};