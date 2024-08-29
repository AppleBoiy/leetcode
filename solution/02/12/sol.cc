#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class TrieNode {
public:
    TrieNode* children[26] = {nullptr};
    string word = "";
};

class Solution {
private:
    TrieNode* root;

    void insertWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c - 'a']) {
                node->children[c - 'a'] = new TrieNode();
            }
            node = node->children[c - 'a'];
        }
        node->word = word;
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, unordered_set<string>& result) {
        char c = board[i][j];
        if (c == '#' || !node->children[c - 'a']) return;

        node = node->children[c - 'a'];
        if (!node->word.empty()) {
            result.insert(node->word);
        }

        board[i][j] = '#';
        if (i > 0) dfs(board, i - 1, j, node, result);
        if (j > 0) dfs(board, i, j - 1, node, result);
        if (i < board.size() - 1) dfs(board, i + 1, j, node, result);
        if (j < board[0].size() - 1) dfs(board, i, j + 1, node, result);
        board[i][j] = c;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        unordered_set<string> result;

        for (string& word : words) {
            insertWord(word);
        }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root, result);
            }
        }

        return vector<string>(result.begin(), result.end());
    }
};