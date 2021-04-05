//브루트포스(재귀)
#include <iostream>

int recur(int sum, int n) {
    if (sum > n) return 0;
    else if (sum == n) return 1;
    int result = 0; //전역변수로 선언하면 재귀호출 안에서 result 값이 바뀌어서 바깥쪽에서 result+= 할 때 누적됨
    for (int i = 1; i <= 3; i++) {
        result+=recur(sum + i, n);
    }
    return result;
}

int main()
{
    int t, n;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        printf("%d\n",recur(0, n));
    }

    return 0;
}
