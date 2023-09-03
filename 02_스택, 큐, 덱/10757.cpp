#include <iostream>
#include <stack>

using namespace std;

string addBigNum(string a, string b) {
	stack <int> stk;
	string result;

	// a와 b의 인덱스 값은 첫째자리부터 더하기 위해 문자열의 가장끝 인덱스로 초기화한다.
	int aidx(a.size() - 1), bidx(b.size() - 1), carry(0);

	while (aidx >= 0 || bidx >= 0) {
		// a와 b에 더할 자릿수가 남아있는 동안 반복
		
		// a 혹은 b에 더이상 자릿수가 남아있지 않지만 반대편 숫자에는 남아있을 때
		// 자릿수가 남은 숫자만 더해줌
		if (aidx < 0) {	
			stk.push((b[bidx]-'0'+carry)%10);
			carry = (b[bidx]-'0'+carry)/10;
		}
		else if(bidx < 0) {
			stk.push((a[aidx]-'0'+carry)%10);
			carry = (a[aidx]-'0'+carry)/10;
		}
		// 일반적으로 a, b 모두의 자릿수가 존재할 때
		// carry는 받아올림, stk에는 한자리 계산 결과를 저장
		else {
			stk.push((a[aidx] + b[bidx] - 2 * '0' + carry) % 10);
			carry = (a[aidx] + b[bidx] -2 * '0' + carry) / 10;
		}

		aidx--; bidx--;
		// stk은 스택이므로 첫째자리가 가장 밑으로 큰 자릿수가 점점 위로 쌓임
	}

	// 만약 남은 받아올림 수가 있다면 스택에 넣어줌
	if (carry) {
		stk.push(carry);
	}

	// 스택의 값을 큰 자릿수부터 result 벡터에 옮겨줌
	while (!stk.empty()) {
		result.push_back(stk.top()+'0');
		stk.pop();
	}

	return result;
}

int main(){
	string a, b;
	cin >> a >> b;
	cout << addBigNum(a, b);
}
