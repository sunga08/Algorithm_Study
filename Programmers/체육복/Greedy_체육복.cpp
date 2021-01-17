
#include <iostream>
#include <vector>
using namespace std;

//int solution(int n, vector<int> lost, vector<int> reserve);

//int main()
//{
//    int r = solution(4, {2,3}, {3,4});
//    printf("%d\n", r);
//
//    return 0;
//}

int solution(int n, vector<int> lost, vector<int> reserve) {
    int cnt = 0;
    int answer = n - lost.size();

    for (int i = 0; i < lost.size(); i++) { //lost 배열

        for (int j = 0; j < reserve.size(); j++) { //reserve 배열

            if (j < reserve.size() - 1 && reserve[j + 1] == lost[i]) {  // lost[2,3] , reserve[3,4] 같은 경우 그냥 통과
                continue;
            }
            else if (i < lost.size() - 1 && lost[i + 1] == reserve[j]) { // lost[3,4] , reserve[2,3] 같은 경우 그냥 통과
                continue;
            }

            if (abs(lost[i] - reserve[j]) <= 1) { //두 배열 원소의 차가 1이하일 때 빌릴 수 있음(자기 자신을 포함하므로 0 포함)
                cnt++;
                reserve[j] = -1;
                break;

            }
        }
    }
    answer += cnt;

    return answer;
}

