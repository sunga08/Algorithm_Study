#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int p1, p2;
int check[101];
int answer = -1; //촌수를 연결할 수 없으면 그대로 -1 출력
void dfs(vector<vector<int>> relation, int p1, int p2, int cnt) {
    check[p1] = 1;
    if (p1 == p2) {
        answer = cnt;
        return;
    }
    
    for (int i = 0; i < relation[p1].size(); i++) {
        if (check[relation[p1][i]] == 0) {
            dfs(relation, relation[p1][i], p2, cnt + 1);
        }
    }
}

int main()
{
    int n, m; //전체 사람 수, 관계 수
    scanf("%d", &n);
    scanf("%d %d", &p1, &p2);
    scanf("%d", &m);
    vector<vector<int>> relation(n+1);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        relation[u].push_back(v);
        relation[v].push_back(u);
    }

    dfs(relation, p1, p2, 0);

    printf("%d", answer);

    return 0;
}
