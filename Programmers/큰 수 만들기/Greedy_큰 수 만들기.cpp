#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int len = number.length();
    int max = -1, idx=-1;  
    
    for (int i = 0; i < len - k ; i++) { //k개 제거했을 때 만들어지는 자릿수 갯수 만큼 돌기
        max = -1;
        for (int j = idx + 1; j <= k+i ; j++) { //이전 max 이후 인덱스 부터, 마지막 인덱스에서 남은 자릿수 개수를 뺀 인덱스까지 
            
            if (max < number[j] - 48) {
                max = number[j] - 48;
                idx = j; //다음 루프에서는 max 이후부터 돌기 위해서 idx를 바꿈
                
            }

        }
        answer+=max+48; //숫자를 다시 문자로 바꾸기 위해 +48
    }

    return answer;
}
