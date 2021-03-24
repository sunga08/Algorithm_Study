#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
int board[101][101]; //주어지는 2차원 배열
int visit[101][101]; //방문여부 표시
int dis[101][101]; //거리 계산
int dx[4] = { 1,0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int n, m;
void bfs(int x, int y) {
    visit[x][y] = true;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (newX > 0 && newX <= n && newY>0 && newY <= m) {
                //갈 수 있는 경우
                if (board[newX][newY] == 1 && visit[newX][newY] == 0) {
                    dis[newX][newY] = dis[x][y] + 1; //거리 증가
                    visit[newX][newY] = 1; //방문 표시
                    if (newX == n && newY == m) return;
                    q.push(make_pair(newX, newY));
                    
                }
            }
        }
    }
    
}

int main()
{

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%1d", &board[i][j]);
        }
    }

    bfs(1, 1);

    printf("%d", dis[n][m]+1);

    return 0;
}
