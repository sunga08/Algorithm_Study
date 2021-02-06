#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {

    vector<int> answer;

    int width = brown + yellow;

    for (int i = 1; i <= width / 2; i++) {
        if (width % i == 0) { //약수인 수에 대하여
            int n = i; //가로
            int m = width / n; //세로
            if (n < m) //세로가 더 큰 경우
                continue;
            int yl = (n - 2) * (m - 2); //yellow 블록은 가로, 세로에서 2개씩 빼서 곱한 갯수
            int br = width - yl; //br+yl = width에 의해서
            if (yl == yellow && br == brown) { //n, m으로 구한 yellow, brown 블록이 input과 같다면 답
                answer.push_back(n);
                answer.push_back(m);
                break;
            }
        }
    }

    return answer;
}
