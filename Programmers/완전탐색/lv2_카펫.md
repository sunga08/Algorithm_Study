- 넓이를 기준으로 가능한 가로, 세로를 구하고 yellow, brown의 개수와 맞는지 확인하는 방법
```c++
#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {

    vector<int> answer;

    int width = brown + yellow;

    for (int i = 1; i <= width / 2; i++) {
        if (width % i == 0) { //약수인 수에 대하여
            int n = i; //가로
            int m = width / n; //세로
            if (n < m) //세로가 더 큰 경우
                continue;
            int yl = (n - 2) * (m - 2); //yellow 블록은 가로, 세로에서 2개씩 빼서 곱한 갯수
            int br = width - yl; //br+yl = width에 의해서
            if (yl == yellow && br == brown) { //n, m으로 구한 yellow, brown 블록이 input과 같다면 답
                answer.push_back(n);
                answer.push_back(m);
                break;
            }
        }
    }

    return answer;
}
```

### 21.04.12
- 안쪽 직사각형의 가로, 세로를 x,y로 놓고 넓이가 될 수 있는 것을 찾음
```c++
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    for(int i=1;i<=yellow;i++){
        if(yellow%i==0){
            int x = yellow/i;
            int y = i;
            if(x<y) continue;
            if((x+2)*(y+2)==brown+yellow){
                answer.push_back(x+2);
                answer.push_back(y+2);
                break; //**넣고 나면 빠져나오기**
            }
        }
    }
    
    return answer;
}
```
