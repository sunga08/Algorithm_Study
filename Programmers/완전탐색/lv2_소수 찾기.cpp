#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <cmath>

using namespace std;

unordered_set <int> s; //중복 제거
string str = ""; //새로 만들어지는 숫자
bool check[7]; //방문했는지 확인

//백트래킹-순열
void find_all(int depth, int limit, string& numbers) {
    if (depth == limit) return;

    for (int i = 0; i < limit; i++) {
        if (!check[i]) {
            check[i] = true;
            str.push_back(numbers[i]);
            s.insert(stoi(str));
            find_all(depth + 1, limit, numbers);
            str.pop_back();
            check[i] = false;
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    find_all(0, numbers.size(), numbers);

    for (auto num : s) {
        bool isSosu=true;

        if (num == 1||num==0) continue;
        
        for (int j = 2; j <= sqrt(num); j++) {
            if (num % j == 0) {
                isSosu = false;
            }
        }
        if (isSosu) answer++;
    }
    
    return answer;
}
