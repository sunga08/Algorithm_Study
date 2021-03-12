#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int max_cnt=0;

void dfs(string startCity, vector<vector<string>>& tickets, vector<bool>& isVisit, vector<string>& answer, vector<string>& temp, int cnt){
  
    temp.push_back(startCity);
    
    if (max_cnt < cnt) {
        max_cnt = cnt;
        answer = temp;
    }
    
    for(int i=0;i<tickets.size();i++){
        if(!isVisit[i] && tickets[i][0]==startCity){
            isVisit[i]=true;
            dfs(tickets[i][1], tickets, isVisit, answer, temp, cnt+1);
            isVisit[i]=false;
        }
    }
    
    temp.pop_back();
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<bool> isVisit(tickets.size(), false);  
    vector<string> temp;
    int cnt=0;
    sort(tickets.begin(), tickets.end());
    dfs("ICN", tickets, isVisit, answer, temp, cnt);
    
    
    return answer;
}
