#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//정렬 - 사용자 정의 함수 이용

//정렬이 일어나는 방향으로 true를 반환해야 한다.
//합친 문자를 비교해서 오름차순으로 정렬
bool compare(string a, string b) {
    return a + b > b + a; //a+b > b+a
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> temp; //문자열 임시벡터

    for (int i = 0; i < numbers.size(); i++) {
        temp.push_back(to_string(numbers[i])); //numbers를 문자열로 바꿔서 집어넣기
        
    }
    sort(temp.begin(), temp.end(), compare); //compare 조건에 따라서 정렬

    if (temp.at(0) == "0") return "0"; //처음 숫자가 0이면 0반환

    for (int i = 0; i < temp.size(); i++) { //정렬된 temp를 answer에 이어 붙이기
        answer += temp[i];
    }


    return answer;
}

int main()
{
    vector<int> numbers = { 6,10,2 };
    cout << solution(numbers);

    return 0;
}

