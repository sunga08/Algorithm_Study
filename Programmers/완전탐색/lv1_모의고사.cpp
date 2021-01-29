#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer(3);
    int p1[5]={1,2,3,4,5};
    int p2[8]={2,1,2,3,2,4,2,5};
    int p3[10]={3,3,1,1,2,2,4,4,5,5};
    int cnt1=0, cnt2=0, cnt3=0;
    int result[3];
    int j=0;
    
    //p1, p2, p3 배열 돌면서 answers와 같은 숫자가 있으면 카운트 증가 
    //=> result 배열에 넣기
    for(int i=0;i<answers.size();i++){
        if(answers[i]==p1[j])
            cnt1++;
        if(j==4) j=0;
        else j++;
    }
    result[0]=cnt1;

    
    j=0;
    for(int i=0;i<answers.size();i++){
        if(answers[i]==p2[j])
            cnt2++;
        if(j==7) j=0;
        else j++;
    }
    result[1]=cnt2;
    
    j=0;
    for(int i=0;i<answers.size();i++){
        if(answers[i]==p3[j])
            cnt3++;
        if(j==9) j=0;
        else j++;
    }
    result[2]=cnt3;
    
    //answers에 가장 높은 점수인 사람 넣기
    int max=0;
    for(int i=0;i<3;i++){
        //더 큰게 있으면 벡터 모두 비우고 현재 인덱스 삽입
        if(result[i]>max) {
            max=result[i];
            answer.clear();
            answer.push_back(i+1);
        }
        //최대값과 같으면 현재 인덱스 그냥 삽입
        else if(result[i]==max && result[i]!=0){
            answer.push_back(i+1);
        }
    }
       
    sort(answer.begin(), answer.end());

    
    return answer;
}
