#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> m;
    
    for(int i=0;i<clothes.size();i++){
        m[clothes[i][1]]++;
    }
    
    //의상의 종류+1 중 하나씩 택해서 곱하기 (nC1*mC1*kC1)
    //+1은 선택하지 않는 경우
    for(auto data:m){
        answer=answer*(data.second+1);
    }
    
    return answer-1; //3종류 모두 선택하지 않음을 선택한 경우 빼주기
}
