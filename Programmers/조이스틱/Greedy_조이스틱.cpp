#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    string start;
    for (int i = 0; i < name.size(); i++) {
        start += 'A'; //name 길이만큼 A로 채우기
    }
    int nowIdx = 0;
    while (1) {
        answer += min(name[nowIdx] - 'A', 'Z' - name[nowIdx] + 1); //'A'부터 현재 문자까지 순방향 증가or역방향 증가 중 최소값
        start[nowIdx] = name[nowIdx]; //start의 문자를 name의 현재 문자로 바꾸기
        
        if (start == name) { //start와 name이 동일한 문자열이 되면 완료
            return answer;
        }

        //왼쪽 이동 횟수
        int leftIdx = nowIdx;
        int leftCnt = 0;

        while (start[leftIdx] == name[leftIdx]) { //새로운 문자가 나타날 때까지 이동
            leftIdx--; //왼쪽으로 하나씩 이동
            leftCnt++;
            if (leftIdx == -1) { //인덱스가 0보다 작아지는 경우
                leftIdx = name.size() - 1; //마지막 인덱스로 설정
            }
        }

        //오른쪽 이동 횟수
        int rightIdx = nowIdx;
        int rightCnt = 0;
        while (start[rightIdx] == name[rightIdx]) {
            rightIdx++;
            rightCnt++;
            if (rightIdx == name.size()) {
                rightIdx = 0;
            }
        }

        //왼쪽 이동, 오른쪽 이동 중 작은것 선택
        if (leftCnt < rightCnt) {
            answer += leftCnt;
            nowIdx = leftIdx;
        }
        else {
            answer += rightCnt;
            nowIdx = rightIdx;
        }

    }
}

//int main()
//{
//    printf("%d\n",solution("JAMES"));
//    return 0;
//}

