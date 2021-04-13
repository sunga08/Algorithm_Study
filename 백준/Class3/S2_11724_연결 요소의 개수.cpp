#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[1001];
bool visited[1000];
void dfs(int node) {
    visited[node] = true;
    for (int i = 0; i < graph[node].size(); i++){
        if (!visited[graph[node][i]]) {
            dfs(graph[node][i]);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cnt++;
            dfs(i);
        }
    }

    cout << cnt << '\n';

    return 0;
}
