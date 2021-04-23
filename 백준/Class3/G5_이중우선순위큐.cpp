//multiet으로 구현 (중복 원소 허용, 삽입시 자동 정렬)

#include <iostream>
#include <queue>
#include <set>

using namespace std;

priority_queue<int> pq;

int main()
{
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        char op;
        int num;
        cin >> n;
        multiset<int> ms;
        while (n--) {

            cin >> op >> num; 
            //scanf("%c %d", &op, &num)  (X)
          
            if (op == 'I') {
                ms.insert(num);
            }
            else {

                if (!ms.empty() && num == -1) {
                    ms.erase(ms.begin());
                }
                else if (!ms.empty() && num == 1) {
                    auto iter = ms.end(); //end()는 마지막 다음을 가리킴
                    iter--;
                    ms.erase(iter);
                }
                
            }
        
        }

        if (ms.empty()) {
            printf("EMPTY\n");
        }
        else {
            set<int>::iterator it = ms.end();
            it--;
            cout << *it << " " << *ms.begin()<<"\n";
        }
    }

    return 0;
}
