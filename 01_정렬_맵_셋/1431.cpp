#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int getSum(string a) {
    int result(0);
    for (int i = 0; i < a.length(); i++) {
        if (isdigit(a[i])) {
            result += (a[i] - '0');
        }
    }
    return result;
}

bool serialCMP(string a, string b) {
    // 이 함수가 false를 리턴하면 두 원소의 자리가 swap 된다
    bool result(true);

    if (a.length() == b.length()) {
        // 문자열의 길이가 같을 때 시리얼번호의 숫자 합을 비교
        int aSum(getSum(a)), bSum(getSum(b));
        
        if (aSum == bSum) {
            // 시리얼번호의 숫자의 합까지 같다면 
            // b가 a보다 작을 때 false 리턴
            return a<b;
        }

        return bSum < aSum;
    }

    return a.length() < b.length();
}

int main() {
    int n(0);
    cin >> n;
    vector<string> vec(n);
    string tmpString;

    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end(), serialCMP);

    for (auto& k : vec) {
        cout << k << '\n';
    }
}
