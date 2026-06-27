#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rows, cols;

    bool dfs(vector<vector<char>>& board, string& word,
             int r, int c, int idx) {

        if (idx == word.size())
            return true;

        if (r < 0 || c < 0 || r >= rows || c >= cols)
            return false;

        if (board[r][c] != word[idx])
            return false;

        char temp = board[r][c];
        board[r][c] = '#';          // mark visited

        bool found =
            dfs(board, word, r + 1, c, idx + 1) ||
            dfs(board, word, r - 1, c, idx + 1) ||
            dfs(board, word, r, c + 1, idx + 1) ||
            dfs(board, word, r, c - 1, idx + 1);

        board[r][c] = temp;         // backtrack

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        rows = board.size();
        cols = board[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                if (dfs(board, word, i, j, 0))
                    return true;
            }
        }

        return false;
    }
};
void runTest(vector<vector<char>> board, string word, bool expected) {
    Solution sol;
    bool ans = sol.exist(board, word);

    if (ans == expected)
        cout << "PASS\n";
    else
        cout << "FAIL (Expected " << expected << ", Got " << ans << ")\n";
}

int main() {

    runTest(
        {
            {'A','B','C','E'},
            {'S','F','C','S'},
            {'A','D','E','E'}
        },
        "ABCCED",
        true
    );

    runTest(
        {
            {'A','B','C','E'},
            {'S','F','C','S'},
            {'A','D','E','E'}
        },
        "SEE",
        true
    );

    runTest(
        {
            {'A','B','C','E'},
            {'S','F','C','S'},
            {'A','D','E','E'}
        },
        "ABCB",
        false
    );

    return 0;
}