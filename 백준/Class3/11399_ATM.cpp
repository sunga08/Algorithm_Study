//작은 값부터 먼저 선택해서 더할 때 최소가 됨
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    int n;
    scanf("%d", &n);

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    sort(v.begin(), v.end());

    int sum = 0, answer = 0;
    for (int i = 0; i < n; i++) {
        sum += v[i];
        answer += sum;
    }

    printf("%d", answer);
    return 0;
}
