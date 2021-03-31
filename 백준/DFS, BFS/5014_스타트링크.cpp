#include <iostream>
#include <queue>

using namespace std;
const int MAX = 2000000;
bool visit[MAX];
//int btn[MAX] = {-1,};

int main()
{
    int f, s, g, u, d;
    scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
    vector<int> btn(f + 1, -1);

    queue<int> q;
    q.push(s);
    visit[s] = true;
    btn[s] = 0;
    
    //int ans = -1; //이거 없이 왜 안되는지?? (btn[]이 제대로 초기화되지 않았음)
    while (!q.empty()) {
        int now = q.front();     
        q.pop();
        
        if (now == g) {
            //ans = btn[now];
            break;
        }
        if (now + u <= f && visit[now+u]==false) {
            btn[now + u] = btn[now] + 1;
            visit[now+u] = true;
            //if (now + u == g) break;
            q.push(now+u);
        }
        if (now - d > 0 && visit[now-d]==false) {
            btn[now - d] = btn[now] + 1;
            visit[now-d] = true;
            //if (now - d == g) break;
            q.push(now-d);
        }
    }

    if (btn[g] != -1) {
        printf("%d", btn[g]);
    }
    else {
        printf("use the stairs");
    }

    
    return 0;
}
