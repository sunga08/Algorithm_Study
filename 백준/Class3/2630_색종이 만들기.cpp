#include <iostream>

int arr[128][128];
int blue = 0;
int white = 0;
void search(int x, int y, int n) {
    if (n < 1) return;
    int tmp = arr[x][y]; //탐색하는 색종이의 첫번째 원소
    bool check = true; //모두 1또는 0인지 확인하기 위한 변수 => for문 수행 후에도 true면 모든 원소가 1또는 0
    for (int i = x; i < (x+n); i++) {
        for (int j = y; j < (y+n); j++) {
            if (arr[i][j] != tmp) {
                check = false; 
                break;
            }
        }
    }

    if (check && tmp == 0) white++;
    else if (check && tmp == 1) blue++;
    else if (!check) {
        search(x, y, n / 2);
        search(x, y + (n / 2), n / 2);
        search(x + (n / 2), y, n / 2);
        search(x + (n / 2), y + (n / 2), n / 2);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    search(0, 0, n); //시작 x좌표, 시작 y좌표, 한 변의 길이
    
    printf("%d\n", white);
    printf("%d\n", blue);

    return 0;
}
