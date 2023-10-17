// 15665.cpp

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_N 10000

// 입력숫자 중복체크용
vector <bool> num_used(MAX_N+1,false);
// 입력 숫자 저장 벡터(오름차순)
vector <int> num;

void getSeq(int m, vector <int> seq){
    // 수열의 길이가 m이 되면 수열 출력 후 반환
    if(seq.size()==m){
        for(int j = 0; j<m; j++){
            cout<<seq[j]<<' ';
        }
        cout<<'\n';
        return;
    }

    for(int i = 0; i<num.size(); i++){
        // i번째 원소를 넣고 재귀호출, 재귀리턴시 다음 숫자를 넣기 위해 pop
        seq.push_back(num[i]);
        getSeq(m,seq);
        seq.pop_back();
    }
}

int main(){
    // 입출력 동기화 해제
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, tmp;
    cin>>n>>m;

    for(int i = 0; i<n; i++){
        cin>>tmp;
        if(!num_used[tmp]){
            // 입력받은 숫자가 중복이 아니면 push
            num_used[tmp]=true;
            num.push_back(tmp);
        }
    }

    // 수열을 오름차순으로 나오게 하기 위해 벡터 정렬
    sort(num.begin(),num.end());
    vector <int> ans;
    getSeq(m,ans);
}