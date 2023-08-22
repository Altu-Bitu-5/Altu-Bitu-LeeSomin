#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int getSum(string a) {
    int result(0);
    for (int i = 0; i < a.length(); i++) {
        if ((a[i] - 48) / 10 == 0) {
            // ASCII에서 48-57은 정수 0-9를 의미
            // 따라서 a에서 48을 뺀 값이 한자리수이면 그 char는 숫자임
            result += (a[i] - 48);
        }
    }
    return result;
}

bool serialCMP(string a, string b) {
    // 이 함수가 false를 리턴하면 두 원소의 자리가 swap 된다
    bool result(true);

    if (a.length() == b.length()) {
        // 문자열의 길이가 같을 때 시리얼번호의 숫자 합을 비교
        int aSum(0), bSum(0);
        aSum = getSum(a);
        bSum = getSum(b);

        if (aSum == bSum) {
            // 시리얼번호의 숫자의 합까지 같다면 
            // b가 a보다 작을 때 false 리턴
            result = a < b;
        }

        else {
            if (bSum < aSum)
                result = false;
        }
    }
    else {
        if (b.length() < a.length())
            result = false;
    }
    return result;
}

int main() {
    int n(0);
    cin >> n;
    vector<string> vec;
    string tmpString;

    for (int i = 0; i < n; i++) {
        cin >> tmpString;
        vec.push_back(tmpString);
    }

    sort(vec.begin(), vec.end(), serialCMP);

    for (auto& k : vec) {
        cout << k << '\n';
    }
}
