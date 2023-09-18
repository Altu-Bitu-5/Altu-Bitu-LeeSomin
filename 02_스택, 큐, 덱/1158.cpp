#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> yosepus(int n, int k){
	vector <int> result;
	queue <int> yosequeue;
	int a(1), curr(0);

	// 사용될 큐 1부터 n까지 초기화
	for (int i = 0; i < n; i++) {
		yosequeue.push(i + 1);
	}

	// 큐에 원소가 사라질 때까지 반복
	while (!yosequeue.empty()) {
		// a가 k의 배수이면 큐의 맨 앞 원소를 결과 벡터에 저장
		// 아닐 시 큐의 맨 뒤에 다시 push
		if (a % k) {
			yosequeue.push(yosequeue.front());
		}
		else {
			result.push_back(yosequeue.front());
			
		}

		yosequeue.pop();
		a++;
	}
	return result;
}

int main(){
	int n(0), k(0);
	vector <int> result;
	cin >> n >> k;

	result = yosepus(n,k);

	// 결과출력
	cout << '<';
	for (int j = 0; j < result.size(); j++) {
		if (j==result.size()-1) {
			cout << result[j] << '>';
		}
		else {
			cout << result[j] << ',';
		}
	}

}
