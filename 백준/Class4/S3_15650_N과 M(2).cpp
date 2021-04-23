#include <iostream>

using namespace std;
bool check[8];
int arr[8];
int n, m;
void dfs(int num, int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m;i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    for (int i = num; i <= n; i++) {
        if (check[i] == false) {
            check[i] = true;
            arr[cnt] = i;
            dfs(i+1, cnt + 1); //현재 배열에 넣는 숫자 다음부터 dfs 시작해야 현재 숫자보다 작은 숫자가 선택되지 않음
            check[i] = false;
        }
    }
}
int main()
{
    cin >> n >> m;

    dfs(1,0);

    return 0;
}
