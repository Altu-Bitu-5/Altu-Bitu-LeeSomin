#include <iostream>

// MAX는 2^20-1로 1인 비트가 20개 존재하는 수이다. 
#define MAX 1024*1024-1

using namespace std;

int bitMasking(string func, int set, int x) {
	// shift연산으로 이진수의 x번째 비트를 1로 설정한다.
	int x_bin = 1 << (x - 1);
	if (func == "add") {
		// or연산으로 비트마스킹에 x를 추가한다. 
		set |= x_bin;
	}
	else if (func == "remove") {
		// x번째 비트를 제외한 모든 비트가 1인 수와 
		// and 연산을 하여 x를 제거한다.
		set &= (MAX ^ x_bin);
	}
	else if (func == "toggle") {
		// xor연산으로 x번째 비트를 뒤집는다.
		set ^= x_bin;
	}
	else if (func == "all") {
		// 모든 비트를 1로 바꾸어준다.
		set = MAX;
	}
	else if (func == "empty") {
		// 모든 비트를 0으로 바꾸어준다. 
		set = 0;
	}
	return set;
}

int main() {
	// 입출력 단축
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int m, x, chk, set = 0;
	string func;

	cin >> m;
	for(int i=0; i<m; i++) {
		cin >> func;
		// all 커맨드와 empty 커맨드는 x값을 받지 않는다. 
		if (func == "all" || func == "empty") {
			x = 0;
		}
		else {
			cin >> x;
			if (func == "check") {	
				// chek에서는 별도로 비트마스킹 변수를 바꿀 필요 없이
				// 바로 비트가 차있는지 확인하여 출력한다. 
				chk = set & (1 << (x - 1)) ? 1 : 0;
				cout << chk << '\n';
				continue;
			}
		}
		// func에 들어온 값에 따라 비트마스킹을 실행해준다.
		set = bitMasking(func, set, x);
	}
}