//다이나믹 프로그래밍
#include <iostream>

int d[1000001]; //memoization 배열
int recur(int n) {
    if (n == 1) { //가장 작은 크기의 문제
        return 0;
    }
    if (d[n] > 0) { //memoization 수행
        return d[n];
    }
    d[n] = recur(n - 1) + 1; //항상 할 수 있는 방법 먼저 확인
    if (n % 2 == 0) {
        int temp = recur(n / 2) + 1;
        if (d[n] > temp) {
            d[n] = temp;
        }
    }
    if (n % 3 == 0) {
        int temp = recur(n / 3) + 1;
        if (d[n] > temp) {
            d[n] = temp;
        }
    }
    return d[n];
}
int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", recur(n));
    return 0;
}
