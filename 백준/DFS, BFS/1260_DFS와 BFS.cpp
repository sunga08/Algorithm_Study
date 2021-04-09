#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void dfs(int start, vector<vector<int>> graph, vector<bool>& check) {
    check[start] = true;
    printf("%d ", start);
    
    for (int i = 0; i < graph[start].size(); i++) {
        int next = graph[start][i];
        if (check[next] == false) {
            dfs(next, graph, check);
        }
    }

}

void bfs(int start, vector<vector<int>> graph, vector<bool>& check) {
    queue<int> q;
    q.push(start);
    check[start] = true;

    while (!q.empty()) {
        int tmp = q.front();
        printf("%d ", tmp);
        q.pop();
        for (int i = 0; i < graph[tmp].size(); i++) {
            if (check[graph[tmp][i]] == false) {
                q.push(graph[tmp][i]);
                check[graph[tmp][i]] = true;
            }
        }
    }
}

int main()
{
    int n, m, start; //노드, 간선, 시작점
    scanf("%d %d %d", &n, &m, &start);

    vector<vector<int>> graph(n + 1); //인접리스트
    vector<bool> check(n + 1); 

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    //정점 번호가 작은 것을 먼저 방문한다고 했으므로 정렬
    //(인접리스트는 연결되어 있는 정점을 검사하는 순서가 인접리스트에 저장되어 있는 순서와 같기 때문에 정렬 필요)
    for (int i = 0; i < n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(start, graph, check);
    fill(check.begin(), check.end(), false);
    printf("\n");
    bfs(start, graph, check);

    return 0;
}
