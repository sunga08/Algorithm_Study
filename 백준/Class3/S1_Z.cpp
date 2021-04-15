//r행 c열이 어느 사분면에 속하는지 재귀적으로 찾아가기
//r행 c열이 속하지 않은 사분면은 볼 필요가 없음 => 숫자만 더해주기

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int r=0, c = 0;
int answer = 0;
void Z(int nowX, int nowY, int size, int cnt) { //nowX, nowY는 각 사분면의 시작 좌표 , cnt는 이전 직전 사분면의 마지막 좌표 값
    answer += cnt;

    if (size == 0) {
        return;
    }

    if (r < nowX + size / 2 && c < nowY + size / 2){
        Z(nowX, nowY, size / 2, 0);
    }

    else if (r< nowX + size / 2 && c >= nowY + size / 2) {
        Z(nowX, nowY+(size/2), size / 2, (size/2)*(size/2)); 
    }

    else if (r >= nowX + size / 2 && c < nowY + size / 2) {
        Z(nowX+(size/2), nowY, size / 2, (size/2)*(size/2)*2);
    }

    else if (r >= nowX + size / 2 && c >= nowY + size / 2) {
        Z(nowX+(size/2), nowY+(size/2), size / 2, (size/2)*(size/2)*3);
    }
}


int main()
{
    int n;
    cin >> n >> r >> c;

    Z(0, 0, pow(2, n), 0);
    printf("%d", answer);

    return 0;
}
