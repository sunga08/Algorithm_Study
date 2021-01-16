
#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve);

//int main()
//{
//    int r = solution(4, {2,3}, {3,4});
//    printf("%d\n", r);
//
//    return 0;
//}

int solution(int n, vector<int> lost, vector<int> reserve) {
    int cnt = 0, k = 0, m = 0;
    int answer = n - lost.size();


    for (int i = 0; i < lost.size(); i++) {
        for (int j = i + 1; j < lost.size(); j++) {
            if (lost[i] > lost[j]) {
                int temp = lost[i];
                lost[i] = lost[j];
                lost[j] = temp;
                break;
            }
        }
    }

    for (int i = 0; i < lost.size(); i++) {

        for (int j = 0; j < reserve.size(); j++) {

            if (j < reserve.size() - 1 && reserve[j + 1] == lost[i]) {
                continue;
            }
            else if (i < lost.size() - 1 && lost[i + 1] == reserve[j]) {
                continue;
            }

            if (abs(lost[i] - reserve[j]) <= 1) {
                cnt++;
                reserve[j] = -1;
                break;

            }
        }
    }
    answer += cnt;

    return answer;
}

