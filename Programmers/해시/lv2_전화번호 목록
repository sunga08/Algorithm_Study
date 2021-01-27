#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//해시로 풀이X
bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());
    //오름차순 정렬 후 앞뒤 숫자만 비교 => 접두사인 숫자는 접두사를 포함하는 숫자의 앞에 옴
    
    int i=1;
    while(answer!=false && i<phone_book.size()){
        answer=false;
        
        //앞의 숫자 길이가 더 크면 뒷 숫자의 접두사는 될 수 없음(true)
        if(phone_book[i-1].size()>phone_book[i].size()) {
            answer=true;  
            i++;
            continue;
        }
        
        //앞 숫자 길이 만큼만 같은 숫자가 있는지 찾기      
        for(int j=0;j<phone_book[i-1].size();j++){            
            //같지 않은게 있으면 break (접두사가 될 수 없음 => true)
            if(phone_book[i][j]!=phone_book[i-1][j]){
                printf("%c ",phone_book[i][j]);
                answer=true;
                break;
            }   
        }
        i++;
        //그대로 나오면 false
    }
    
    return answer;
}
