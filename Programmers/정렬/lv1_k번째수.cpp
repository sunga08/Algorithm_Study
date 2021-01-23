#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (int n = 0; n < commands.size();n++) {
        int i = commands[n][0], j = commands[n][1], k = commands[n][2];
        int t = 0;

        vector<int> temp(j - i + 1);
        for (int m = i - 1; m <= j - 1; m++) temp[t++] = array[m];
        sort(temp.begin(), temp.end());
        answer.push_back(temp[k - 1]);


        //다른풀이 (for문 사용X)
        //원래 배열에서 i,j 범위만큼만 정렬

        /*vector<int> temp = array;
        sort(temp.begin() + i - 1, temp.begin() + j); 
        answer.push_back(temp[i - 1 + k - 1]);*/

    }

    return answer;
}
int main()
{
    
    vector<int> array = { 1,5,2,6,3,7,4 };
    vector<vector<int>> command = { {2,5,3},{4,4,1},{1,7,3} };

    solution(array, command);

    return 0;
}
