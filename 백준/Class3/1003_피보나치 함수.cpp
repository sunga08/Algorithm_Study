//Dynamic Programming 문제
//재귀호출할 때 계산되는 값을 배열에 저장(메모이제이션) => 한 번 계산했던것을 다시 계산하지 않는다

#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> memo(40); //memo[i] = fibo(i)가 계산된 값, (0의 갯수, 1의 갯수) 쌍으로 저장

pair<int,int> fibo(int n) {
    if (n == 0) {
        memo[n].first = 1;
        return make_pair(1,0);
    }
    else if (n == 1) {
        memo[n].second = 1;
        return make_pair(0,1);
    }
    else {
        if (memo[n].first > 0 && memo[n].second > 0) { //memo[n] = (0,0)일때 n은 아직 계산되지 않은 것 => 0보다 크면 계산된 것이므로 계산된 값 memo[n]을 리턴  
            return memo[n];
        }
        memo[n].first = fibo(n - 1).first + fibo(n - 2).first; 
        memo[n].second = fibo(n - 1).second + fibo(n - 2).second;
        return memo[n];
    }
}

int main()
{
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);  
        fill(memo.begin(), memo.end(), make_pair(0, 0));
        fibo(n);
        printf("%d %d\n", memo[n].first, memo[n].second);
    }

    return 0;
}
