#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> m; //이름과 출현횟수 저장

    //맵은 기존에 key가 있으면 덮어쓰게 됨
    for (auto data : completion) {
        if (m.find(data) == m.end()) m[data] = 1; //저장되어 있지 않는 key이면 value=1
        else m[data]++; //이미 key가 있는 경우 value++ 
    }

\
    for (auto str:participant) {
        if (m.find(str) == m.end()) //찾지 못한다면 -> 완주자 목록에는 없는 사람
            answer = str;
        else { //참가자 목록과 완주자 목록에 모두 있는 경우
            m[str]--;
            if (m[str] < 0) //0보다 작아지면 같은 이름이 참가자에만 하나 더 있는 것
                answer = str;
        }
    }


    return answer;
}

int main()
{
    vector<string> participant = { "mislav", "stanko", "mislav", "ana"};
    vector<string> completion = { "mislav", "stanko", "ana" };

    solution(participant, completion);

    return 0;
}

