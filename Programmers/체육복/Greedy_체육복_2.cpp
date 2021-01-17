#include <iostream>
#include <vector>

using namespace std;


int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = n;
	vector<int> res(n+1);
	for (int i = 0; i < n; i++) res[i] = 1;

	for (int i = 0; i < lost.size(); i++) {
		res[lost[i]]--;
	}

	for (int i = 0; i < reserve.size(); i++) {
		res[reserve[i]]++;
	}

	for (int i = 1; i <= n; i++) {	
		if (res[i] == 0) {
			if (i != n && res[i] == 0 && res[i + 1] == 2) {
				res[i]++;
				res[i + 1]--;
			}
			else if (i != 1 && res[i] == 0 && res[i - 1] == 2) {
				res[i]++;
				res[i - 1]--;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (res[i] == 0) answer--;
	}

	return answer;
}

int main()
{

}

