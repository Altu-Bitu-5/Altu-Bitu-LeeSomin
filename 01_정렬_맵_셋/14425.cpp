#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int countSameString(set<string> S, vector<string> M) {
    int sIdx(0), mIdx(0), result(0);

    for(int i = 0; i<M.size();i++){
        if(S.find(M[i])!=S.end()){
            result++;
        }
    }
    return result;
}

int main() {
    int n(0), m(0);
    int result(0);
    cin >> n >> m;

    set<string> S;
    vector<string> M;

    string tmp_string;
    for (int i = 0; i < n; i++) {
        cin>>tmp_string;
        S.insert(tmp_string);
    }

    for (int j = 0; j < m; j++) {
        cin>>M[j];
    }

    cout << countSameString(S, M) << endl;

}