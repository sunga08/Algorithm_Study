//시작시간 기준으로 정렬하면 (1,6)(2,3)(3,4)(4,5)(6,8)와 같은 경우 (1,6)(6,8) 사이에 있는 것을 선택할 때 더 많이 선택할 수 있는 경우가 생기게 됨 
//종료시간 기준으로 정렬 => 종료시간이 같은면 그 중 어떤걸 선택해도 결과가 같다.
//(1,4)(2,4)(3,4)(5,10) => (1,4)~(3,4) 어떤걸 선택해도 그 다음에 (5,10)을 선택하게 됨

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v;

bool comp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second == p2.second) { //끝나는 시간이 같으면
        return p1.first < p2.first; //시작 시간 기준으로 오름차순 정렬
    }
    else {
        return p1.second < p2.second; //종료 시간 기준으로 오름차순 정렬
    }
}

int main()
{
    int n;
    cin >> n;
    
    
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        v.push_back(make_pair(a, b));
    }

    sort(v.begin(), v.end(), comp);

    int cnt = 1, end = v[0].second;

    for (int i = 1; i < n; i++) {
        if (v[i].first >= end) { //현재 종료시간보다 큰 시작 시간이 있으면
            cnt++; 
            end = v[i].second; //종료시간 바꿔주기
        }
    }

    printf("%d\n", cnt);
    return 0;
}
