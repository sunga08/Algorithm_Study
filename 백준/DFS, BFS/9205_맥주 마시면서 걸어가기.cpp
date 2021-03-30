#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

vector<int> graph[102]; //갈 수 있는 지점을 연결한 그래프
bool visit[102];

//두 좌표 사이의 거리 계산
int distance(pair<int,int> p1, pair<int,int> p2) {
    return abs(p2.first - p1.first) + abs(p2.second - p1.second);
}

void dfs(int node) {
    visit[node] = true;
    for (int i = 0; i < graph[node].size(); i++) {
        int next = graph[node][i];
        if (visit[next] == false) {
            dfs(next);
        }
    }
}

int main()
{
    int t, n;
    scanf("%d", &t);
    

    for (int i = 0; i < t; i++) {
        //graph 초기화
        for (int j = 0; j < 102; j++) {
            graph[j].clear();
        }
        //visit 초기화
        memset(visit, false, sizeof(visit));
        scanf("%d", &n);
        vector<pair<int, int>> coord; //좌표 저장하는 벡터
        
        //좌표 입력 받아서 coord 벡터에 넣기
        for (int j = 0; j < n + 2; j++) {
            int x, y;
            scanf("%d %d", &x, &y);
            coord.push_back(make_pair(x, y));
        }

        //맥주가 떨어지지 않고 갈 수 있는 좌표면 graph 연결
        for (int j = 0; j < n + 2; j++) {
            for (int k = 0; k < n + 2; k++) {
                if (distance(coord[j], coord[k]) <= 50 * 20) { //맥주가 떨어지지 않고 갈 수 있는 거리는 1000m
                    graph[j].push_back(k);
                    graph[k].push_back(j);
                }
            }
        }

        //완성한 그래프에 대하여 dfs 수행
        dfs(0);

        //마지막 지점을 방문함=종료지점까지 감
        if (visit[n + 1]) printf("happy\n");
        else printf("sad\n");

    }

    return 0;
}
