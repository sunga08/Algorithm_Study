#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int len = number.length();
    int max = -1, idx, cnt = len - k, n = 0; //cnt=자릿수
    vector<int> res(len - k);

    for (int i = 0; i <= len - k; i++) {
        if (max < number[i] - 48) {
            max = number[i] - 48;
            idx = i;

        }
    }
    // printf("max1: %d \n",max);

    answer.push_back(max + 48);

    cnt--;
    max = 0;
    for (int i = 0; i < len - k - 1; i++) { //k개 제거했을 때 숫자 길이-1만큼
        max = 0;
        for (int j = idx + 1; j < len; j++) { //max 이후 인덱스 부터 끝까지 돌면서
            //printf("%d\n",len-cnt);
            if (j <= (len - cnt) && max < number[j] - 48) {
                max = number[j] - 48;
                idx = j; //다음 루프에서는 max 이후부터 돌기 위해서 바꿈
                //printf("idx: %d max: %d \n",idx,max)
            }

        }
        cnt--;
        //printf("max2: %d cnt: %d\n",max,cnt);

        answer.push_back(max + 48);
    }

    //cout<<"answer: "+answer;

    return answer;
}
