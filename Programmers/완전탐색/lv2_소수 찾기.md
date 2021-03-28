
## C++ 풀이
```c++
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
```

## JAVA 풀이
```java
import java.util.*;
class Solution {
    HashSet<Integer> set = new HashSet<>();
    //String result = ""; //이어 붙인 문자열
    StringBuffer result = new StringBuffer();
    boolean[] check = new boolean[7];
        
    public int solution(String numbers) {
        int answer = 0;
        
        combination(0,numbers.length(),numbers);
        
        //소수 판단
        
        for(Integer num:set){
            boolean isPrime=true;
            if(num==0||num==1) continue;
            
            else{
                for(int i=2;i<=Math.sqrt(num);i++){
                    if(num%i==0){
                        isPrime=false;
                        break;
                    }
                }
            }
            
            if(isPrime) answer++;
            
        }
        
        
        return answer;
    }
    
    public void combination(int depth, int limit, String numbers){
        if(depth==limit) return;
        for(int i=0;i<limit;i++){
            if(!check[i]){
                check[i]=true;
                result.append(numbers.charAt(i));
                set.add(Integer.valueOf(result.toString()));
                combination(depth+1,limit,numbers);
                result.deleteCharAt(result.length()-1);
                
                check[i]=false;
            }
        }
    }
}
```

## 3/28 C++ 
```c++
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;
set<int> all_numbers;
//bool visit[7];
string tmp="";
void search_all(int depth, int end, string numbers, vector<bool>& visit){
    if(depth==end) return;
    for(int i=0;i<end;i++){
        if(visit[i]==false){
            visit[i]=true;
            tmp += numbers.at(i);
            all_numbers.insert(stoi(tmp));
            search_all(depth+1, end, numbers, visit);
            visit[i]=false;
            tmp = tmp.substr(0,tmp.size()-1);
        }
    }
}
int solution(string numbers) {
    int answer = 0;
    vector<bool> visit(numbers.size());
    
    search_all(0, numbers.size(), numbers, visit);
        
    for(auto elem:all_numbers){
        bool isPrime=true;
        if(elem<=1) continue;
        if(elem==2) answer++;
        
        for(int i=2;i<=sqrt(elem);i++){
            if(elem%i==0){
                isPrime=false;
                break;
            }
        }
        
        if(isPrime) answer++;
    }
    
    return answer;
}
```
