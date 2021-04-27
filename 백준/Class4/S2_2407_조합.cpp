#include <iostream>
#include <string>
#include <algorithm>

//nCm
using namespace std;
string memo[101][101];

string calBigNum(string s1, string s2) {
    string result = "";
    int sum = 0;

    while (!s1.empty() || !s2.empty() || sum==1) { //s1, s2가 비어있어도 sum=1이면 result에 1을 더해줘야 함

        //맨 뒤 부터(1의 자리) 더하기
        if (!s1.empty()) {
            sum += s1.back() - '0'; 
            s1.pop_back();
        }

        if (!s2.empty()) {
            sum += s2.back() - '0';
            s2.pop_back();
        }

        result.push_back((sum % 10)+'0'); //더한 값의 1의 자리만 문자열에 추가
        sum /= 10; //1의 자리 더한 값이 10 이상이면 다음 자리수 계산할 때 +1

    }

    reverse(result.begin(), result.end());

    return result;
}

string combi(int n, int m) {
    string result = "";

    if (memo[n][m] != "") { //이미 계산된 값이 있는 경우
        return memo[n][m];
    }
    else if (m == 0 || n == m) { //nC0, nCn = 1
        return "1";
    }

    return memo[n][m] = calBigNum(combi(n - 1, m - 1), combi(n - 1, m));
    
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    cout << combi(n, m) << "\n";

    return 0;
}
