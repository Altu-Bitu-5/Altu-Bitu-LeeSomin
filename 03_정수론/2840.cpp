#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <char> getRoulette(int n, vector<pair<int, char>> rec) {
    // 조건에 맞는 룰렛을 구하는 함수
	vector <char> roulette(n, '?');
	int idx_rlt(0);
    // 맨 마지막에 나온 문자부터 차례로 탐색
	for (int i = rec.size() - 1; i >= 0; i--) {
        // 이미 해당 자리에 다른 문자가 들어있으면 해당하는 룰렛이 존재하지 않음
		if (roulette[idx_rlt] != '?' && roulette[idx_rlt] != rec[i].second) {
			roulette.clear();
			roulette.push_back('!');
			break;
		}
		roulette[idx_rlt] = rec[i].second;
		idx_rlt +=rec[i].first;
		idx_rlt %= n;

        // 같은 문자가 두 칸 이상 존재하면 해당 룰렛이 존재하지 않음
		if (1<count(roulette.begin(), roulette.end(), rec[i].second)) {
			roulette.clear();
			roulette.push_back('!');
			break;
		}
	}
	return roulette;
}

int main() {
	int n(0), k(0);
	cin >> n >> k;
	vector<pair<int, char>> rec(k);
	for (int i = 0; i < k; i++) {
		cin >> rec[i].first >> rec[i].second;
	}
	vector <char> rulet = getRoulette(n, rec);
	for (auto a : rulet) {
		cout << a;
	}
	cout << '\n';
}
