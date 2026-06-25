#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector <int> x{1, -1, 0, 0};
    vector <int> y={0, 0, 1, -1};
    void bfs(vector<vector<char>>&board, queue<pair<int, int>>&q, vector<vector<int>>&visited){
        int m=board.size();
        int n=board[0].size();

        while(!q.empty()){
            auto [i, j]=q.front();
            q.pop();
            board[i][j]='S';
            for(int k=0; k<4; k++){
                if(i+x[k]>=0&&i+x[k]<m&&j+y[k]>=0&&j+y[k]<n){
                    if(visited[i+x[k]][j+y[k]]==0&&board[i+x[k]][j+y[k]]=='O'){
                        q.push({i+x[k], j+y[k]});
                        visited[i+x[k]][j+y[k]]=1;
                    }
                }
            }
        }
        return;
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector <vector<int>> visited(m, vector<int>(n, 0));
        queue<pair<int,int>> q;
        for(int i=0; i<m; i++){
            if(board[i][0]=='O') {
                q.push({i, 0});
                visited[i][0]=1;
            }
        }
        for(int i=0; i<m; i++){
            if(board[i][n-1]=='O') {
                q.push({i, n-1});
                visited[i][n-1]=0;
            }
        }
        
        for(int j=0; j<n; j++){
            if(board[0][j]=='O'){
                 q.push({0, j});
                 visited[0][j]=1;
            }
        }
                
        for(int j=0; j<n; j++){
            if(board[m-1][j]=='O') {
                q.push({m-1, j});
                visited[m-1][j]=1;
            }
        }

        bfs(board, q, visited);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]=='O') board[i][j]='X';
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]=='S') board[i][j]='O';
            }
        }
        return;
    }
};

bool equalBoard(const vector<vector<char>>& a,
                const vector<vector<char>>& b) {
    return a == b;
}

void printBoard(const vector<vector<char>>& board) {
    cout << "[\n";
    for (const auto& row : board) {
        cout << "  ";
        for (char c : row)
            cout << c << " ";
        cout << "\n";
    }
    cout << "]\n";
}

void runTest(int testNo,
             vector<vector<char>> board,
             vector<vector<char>> expected) {

    Solution sol;
    sol.solve(board);

    if (equalBoard(board, expected)) {
        cout << "Test " << testNo << " PASSED\n";
    } else {
        cout << "Test " << testNo << " FAILED\n";
        cout << "Expected:\n";
        printBoard(expected);
        cout << "Got:\n";
        printBoard(board);
    }
}

int main() {

    runTest(
        1,
        {
            {'X','X','X','X'},
            {'X','O','O','X'},
            {'X','X','O','X'},
            {'X','O','X','X'}
        },
        {
            {'X','X','X','X'},
            {'X','X','X','X'},
            {'X','X','X','X'},
            {'X','O','X','X'}
        }
    );

    runTest(
        2,
        {
            {'X'}
        },
        {
            {'X'}
        }
    );

    runTest(
        3,
        {
            {'O'}
        },
        {
            {'O'}
        }
    );

    runTest(
        4,
        {
            {'O','O'},
            {'O','O'}
        },
        {
            {'O','O'},
            {'O','O'}
        }
    );

    runTest(
        5,
        {
            {'X','X','X'},
            {'X','O','X'},
            {'X','X','X'}
        },
        {
            {'X','X','X'},
            {'X','X','X'},
            {'X','X','X'}
        }
    );

    runTest(
        6,
        {
            {'O','X','O'},
            {'X','O','X'},
            {'O','X','O'}
        },
        {
            {'O','X','O'},
            {'X','X','X'},
            {'O','X','O'}
        }
    );

    return 0;
}
