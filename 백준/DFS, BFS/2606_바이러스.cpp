#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int cnt = 0;
void bfs(int start, vector<vector<int>>& graph, vector<bool>& check) {
    queue<int> q;
    q.push(start);
    check[start] = true;

    while (!q.empty()) {
        int tmp = q.front();
        q.pop();
        for (int i = 0; i < graph[tmp].size(); i++) {
            if (check[graph[tmp][i]] == false) {
                q.push(graph[tmp][i]);
                check[graph[tmp][i]] = true;
                cnt++;
            }
        }
    }
}

int main(void) {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    vector<vector<int>> graph(n + 1);
    vector<bool> check(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    bfs(1, graph, check);
    printf("%d", cnt);

    return 0;
}
