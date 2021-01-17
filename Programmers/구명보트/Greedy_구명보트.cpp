#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int min = 0; //최소값 인덱스

    sort(people.begin(), people.end()); //오름차순으로 먼저 정렬

    while (min < people.size()) { //최소값 인덱스가 people size 보다 커질때까지
        if (people[min] + people.back()> limit) { //최소값과 최대값이 limit을 초과하면 최대값은 혼자 타야 함
            answer++;
        }
        else{
            answer++;
            min++; //2명이 탈 수 있는 경우 최소값 인덱스 증가
        }
        people.pop_back(); //최대값은 항상 삭제해서 사이즈 줄이기
    }
    
    return answer;
}
