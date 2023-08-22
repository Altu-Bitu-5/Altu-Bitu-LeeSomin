#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int countSameString(vector<string> S, vector<string> M) {
    int sIdx(0), mIdx(0), result(0);

    // 두 문자열 집합 정렬
    sort(S.begin(), S.end());
    sort(M.begin(), M.end());

    while (sIdx < S.size() && mIdx < M.size()) {
        if (S[sIdx] == M[mIdx]) {
            // 두 문자열이 같으면 결과값에 1을 더하고 집합M의 다음 원소로 넘어감
            result++;
            mIdx++;
            continue;
        }

        // 두 문자열을 비교해 오름차순상 더 먼저 오는 문자열이 
        // 속한 집합의 인덱스 값을 1 증가시켜 다음 원소와 다시 비교
        else if (S[sIdx] < M[mIdx])
            sIdx++;
        else
            mIdx++;
    }
    return result;
}

int main() {
    int n(0), m(0);
    int result(0);
    cin >> n >> m;

    vector<string> S;
    vector<string> M;

    string tmp_string;
    for (int i = 0; i < n; i++) {
        cin >> tmp_string;
        S.push_back(tmp_string);
    }

    for (int j = 0; j < m; j++) {
        cin >> tmp_string;
        M.push_back(tmp_string);
    }

    cout << countSameString(S, M) << endl;

}