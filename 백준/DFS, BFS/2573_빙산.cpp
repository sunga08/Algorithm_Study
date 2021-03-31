#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

//배열 하나만 사용하면 다음 좌표에서 바뀐 숫자로 0의 갯수를 판단함  
int board[300][300];
int board2[300][300]; //bfs수행시 결과 저장
bool visit[300][300];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visit[x][y] = true;

	while (!q.empty()) {
		int nowX = q.front().first;
		int nowY = q.front().second;
		q.pop();
		//4방향 확인할 때 board에서 (nextX,nextY)가 0이면 board2의 (nowX, nowY)의 값 1 빼주기
		for (int i = 0; i < 4; i++) {
			int nextX = nowX + dx[i];
			int nextY = nowY + dy[i];
			if (board[nextX][nextY] == 0 && board2[nowX][nowY]>0) {
				board2[nowX][nowY]--;
			}
			else if (visit[nextX][nextY] == false && board[nextX][nextY] != 0) {
				visit[nextX][nextY]=true;
				q.push(make_pair(nextX, nextY));
			}
		}
	}
}
int main()
{
	int m, n;
	scanf("%d %d", &m, &n);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	memcpy(board2, board, sizeof(board)); //board를 board2에 복사

	int year = 0;
	while (1) {
		int cnt = 0; //빙산 덩어리 카운트
		year++;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] > 0 && visit[i][j] == false) {
					cnt++; //새롭게 bfs를 수행하면 분리되어 있는 빙산임
					bfs(i, j);
				}
			}
		}
		memcpy(board, board2, sizeof(board2));//bfs 한번 수행한 결과를 다시 board에 복사
		memset(visit, false, sizeof(visit));

		if (cnt >= 2) { //빙산이 두개 이상으로 분리됨
			printf("%d\n", year-1); //bfs를 수행하고 나온 후에 빙산이 분리되었는지 판단 가능하므로 1 빼주기
			break;
		}
		else if (cnt == 0) { //빙산이 분리되지 않고 모두 녹음
			printf("0");
			break;
		}

	}
	
	return 0;
}
