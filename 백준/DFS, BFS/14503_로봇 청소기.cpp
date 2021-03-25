
#include <iostream>
#include <vector>

using namespace std;

int map[51][51];
bool visit[51][51];
//북-동-남-서
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int cnt = 0;

void dfs(int x, int y, int dir) {

    if (map[x][y] == 0) { //처음 갈 때만 cnt 증가
        map[x][y] = 2;
        cnt++;
    }

    for (int i = 0; i < 4; i++) {
        int nextDir = 0;
        //현재 기준에서 왼쪽 방향으로 바꾸기 (북=0, 동=1, 남=2, 서=3)
        if (dir == 0) nextDir = 3; 
        else nextDir = dir - 1;
      
        int nextX = x + dx[nextDir];
        int nextY = y + dy[nextDir];


        if (map[nextX][nextY]==0) {
            dfs(nextX, nextY, nextDir);
            return; ////한 곳에서 갈 수 있는 모든 방향을 탐색하지 않도록 => dfs 한 번 수행되면 더 이상 다른 방향으로 탐색할 수 없게 하기 
        }
          
        //갈 수 없는 곳이면 방향만 바꾸기
        else {
            dir = nextDir;
        }
       
    }
  
    //for문을 다 돌고 나왔다 = 더 이상 갈 곳이 없음 
    int nextX = x + dx[dir]*(-1);
    int nextY = y + dy[dir]*(-1);
    
    //후진하는 곳이 벽이 아니면 돌아가서 dfs 수행
    if(map[nextX][nextY]!=1)
      dfs(nextX, nextY, dir);

}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int r, c, dir;
    scanf("%d %d %d", &r, &c, &dir);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    dfs(r, c, dir);

    printf("%d", cnt);
    return 0;
}
