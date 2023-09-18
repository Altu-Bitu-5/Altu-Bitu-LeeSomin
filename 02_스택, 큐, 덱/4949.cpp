#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

string isBalanced(string str) {

	stack <char> chstack;
	for (int i = 0; i < str.size(); i++) {
		// 왼쪽 괄호일 시 스택에 push
		if (str[i] == '(' || str[i] == '[') {
			chstack.push(str[i]);
		}

		// 오른쪽 소괄호와 중괄호에 대해 각각 스택 맨 위 원소와 짝이 맞지 않거나 
		// 스택이 비어있으면 "no" 리턴, 짝이 맞으면 스택 pop
		else if (str[i] == ')') {
			if (chstack.empty() || chstack.top() != '(') {
				return "no";
			}
			else {
				chstack.pop();
			}
		}

		else if (str[i] == ']') {
			if (chstack.empty() || chstack.top() != '[') {
				return "no";
			}
			else {
				chstack.pop();
			}
		}

	}

	// 스택에 남은 괄호가 없는지 확인
	if (chstack.empty()) {
		return "yes";
	}
	else {
		return "no";
	}
}

int main(){
	vector <string> strvec;
	string str;
	
	// "."가 입력될 때 까지 문자열 저장
	while (true) {
		getline(cin, str);
		if (str == ".") {
			break;
		}
		strvec.push_back(str);
	}

	//각 문자열에 대해 균형여부 확인
	for (int i = 0; i < strvec.size(); i++) {
		cout<<isBalanced(strvec[i])<<endl;
	}
}
