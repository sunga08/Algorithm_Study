#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[25][25];
int n;
//vector<int> answer;
int dx[4] = { -1,0,1,0 }; //위, 오, 아래, 왼
int dy[4] = { 0,1,0,-1 };

void bfs(int x, int y, int no) {
    arr[x][y] = no;
    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        //조건에 걸리면 갈 수 있는 곳
        if (newX >= 0 && newY >= 0 && newX < n && newY < n && arr[newX][newY]==1) {
            bfs(newX, newY, no);
        }
    }
}


int main()
{
    freopen("input.txt", "rt", stdin);
    int cnt=0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        //string temp;
        //cin >> temp;
        for (int j = 0; j < n; j++) {
            //arr[i][j] = temp[j] - '0';
            scanf("%1d", &arr[i][j]); //공백 없을 때 숫자 하나씩 읽어오기**
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 1) {
                cnt++;
                bfs(i, j, cnt+1);
            }
        }
    }

    //각 단지 숫자가 증가되어 있는 상태

    vector<int> answer(cnt);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(arr[i][j]!=0)  answer[arr[i][j] - 2]++;
        }
    }

    sort(answer.begin(), answer.end());

    printf("%d \n", cnt);

    for (auto i : answer) {
        printf("%d \n", i);
    }

    return 0;
}
