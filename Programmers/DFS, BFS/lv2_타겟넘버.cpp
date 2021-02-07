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
