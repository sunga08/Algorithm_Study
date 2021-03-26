#include <iostream>
#include <queue>

using namespace std;
const int MAX = 200000;
bool check[MAX]; //방문 확인
int dist[MAX]; //이동거리 저장
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    queue<int> q;
    check[n] = true;
    dist[n] = 0;
    q.push(n); //시작위치 큐에 삽입
  
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (now - 1 >= 0) { //다음에 갈 곳 범위 체크
            if (check[now - 1] == false) { //간 적이 없으면
                check[now - 1] = true;
                dist[now - 1] = dist[now]+1; //현재까지 계산한 거리에 +1
                if(now - 1 == k) break;
                q.push(now - 1);
            }
        }

        if (now + 1 < MAX) {
            if (check[now + 1] == false) {
                check[now + 1] = true;
                dist[now + 1] = dist[now] + 1;
                if(now + 1 == k) break;
                q.push(now + 1);
            }
        }

        if (2 * now < MAX) {
            if (check[2 * now] == false) {
                check[2 * now] = true;
                dist[2 * now] = dist[now]+1;
                if(2 * now == k) break;
                q.push(now * 2);
            }
        }

    }

    printf("%d", dist[k]);

    return 0;
}
