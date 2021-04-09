
```c++
#include <string>
#include <vector>

using namespace std;

int answer = 0;
void dfs(vector<int> numbers, int target, int count, int sum){
    if(count==numbers.size(){
        if(sum==target){
            answer++;
            return;
        }
    }
    
    dfs(numbers, target, count+1, sum+numbers[count]);
    dfs(numbers, target, count+1, sum-numbers[count]);

}

int solution(vector<int> numbers, int target) {
    
    dfs(numbers, target, 0, 0);
    
    return answer;
}
```

## 추가(21.04.09)

```c++
#include <string>
#include <vector>

using namespace std;
int result;
int recur(vector<int>& numbers, int sum, int idx, int target, int limit){
    if(idx==limit && sum!=target) return 0;
    if(idx==limit && sum==target) return 1;

    int res=0;
    res+=recur(numbers, sum+numbers[idx], idx+1, target, limit);
    res+=recur(numbers, sum+(numbers[idx]*(-1)),idx+1, target, limit);
    
    return res;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    result=recur(numbers,0,0,target, numbers.size());
    return result;
}
```
