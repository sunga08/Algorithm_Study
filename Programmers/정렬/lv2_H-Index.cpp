#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0, i=0;
    sort(citations.begin(), citations.end(), greater<>()); //내림차순 정렬

    //인용된 횟수 = citations[i], 논문의 편수 = i+1 
    //인용된 횟수가 논문의 편수(index+1)보다 크거나 같을 동안에만 카운트 증가
    //인용된 횟수가 논문의 편수보다 크면 논문의 편수가 h값이 될 수 있음
    while (i + 1 <= citations[i++]) {
        answer++;
    }

    return answer;
}
int main()
{
    vector<int> citations = { 12,11,10,9,8,1 };
    solution(citations);

    return 0;
}
