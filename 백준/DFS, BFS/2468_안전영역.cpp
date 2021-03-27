//board의 겹치지 않는 숫자 n에 대해서 높이가 n이상인 곳에서 dfs 수행
//dfs를 수행한 숫자는 check 배열에서 1로 바꿈 => 기준을 잡은 적이 없는 숫자에 대해서 dfs 수행
//기준 숫자에 대해 dfs 수행한 결과로 안전지대 갯수를 받아 현재 최대값과 비교하여 값 교체

#include <iostream>
#include <utility>

using namespace std;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int board[101][101];
int check[100]; //board에 있는 겹치지 않는 모든 숫자를 한 번씩 기준으로 잡았는지 확인하기 위함
int n;


void dfs(int x, int y, int cur, bool visit[][101]) {
    if (visit[x][y] == true) return;
    visit[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < n && board[nextX][nextY]>=cur) { //cur 이상인 곳만 갈 수 있음
            dfs(nextX, nextY, cur, visit);
        }
    }
}

//cur를 기준으로 dfs를 수행(cur 이상인 곳에서만 dfs 시작 가능)  => dfs가 모두 끝나면 안전지대 갯수를 구할 수 있음
int start_dfs(int cur) {
    bool visit[101][101] = { false, };   
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visit[i][j] == false && board[i][j] >= cur) {
                cnt++; //dfs를 시작할 수 있는 곳이면 안전지대 카운트 증가
                dfs(i, j, cur, visit);
            }
        }
    }

    return cnt;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    int max_cnt = 0;
    //높이가 n미만인 곳 물에 잠기게 할 때 n이 될 수 있는 기준값 구하기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (check[board[i][j]] == 0) {
                check[board[i][j]] = 1; 
                max_cnt = max(max_cnt,start_dfs(board[i][j])); //최대값 비교하여 큰 값으로 바꾸기
            }
        }
    }

    printf("%d", max_cnt);
    return 0;
}
