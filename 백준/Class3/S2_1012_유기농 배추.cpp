//dfs 가능한 경우 카운트하기
#include <iostream>
#include <vector>

using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

void dfs(vector<vector<int>>& board, vector<vector<bool>>& visited, int x, int y, int m, int n) {
    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (newX<n && newX>=0 && newY<m && newY>=0 && board[newX][newY] == 1 && !visited[newX][newY]) {
            dfs(board, visited, newX, newY, m, n);
        }
    }
}

int main(){
    int m,n,t, k;
    cin >> t;

    for (int i = 0; i < t; i++) {  
        cin >> m >> n >> k;
        vector<vector<int>> board(n,vector<int> (m,0));
        vector<vector<bool>> visited(n, vector<bool>(m, 0));

        for (int j = 0; j < k; j++) {
            int x, y;
            scanf("%d %d", &x, &y);
            board[y][x] = 1;
        }


        int cnt = 0;
        for (int a = 0; a < n; a++) {
            for (int b = 0; b < m; b++) {
                if (!visited[a][b]&&board[a][b]==1) {
                    cnt++;
                    dfs(board, visited, a, b, m, n);
                }
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}
