// 20922.cpp

#include <iostream> 
#include <vector>

using namespace std;


int findSubseqLen(vector<int> seq, int k){
    vector <int> dup_cnt (100001, 0);
    int start_idx = 0, end_idx = 0;
    int max_len = 0;

    while(start_idx<=end_idx && end_idx<seq.size()){
        if(dup_cnt[seq[end_idx]]<k){
            // 중복 숫자가 k이하일 떄(마지막 중복숫자는 if 다음 추가됨)
            // 오른쪽 포인터 오른쪽으로 옮겨 수열길이를 늘림
            dup_cnt[seq[end_idx]]++;
            end_idx++;
            if(end_idx-start_idx> max_len){
                // 최대 수열 길이 갱신
                max_len = end_idx - start_idx;
            }
        }
        else{
            // 중복 숫자가 k보다 클 때 제일 중복이 많은 수가 하나 줄어들 때까지
            // 수열 줄여줌
            dup_cnt[seq[start_idx]]--;
            start_idx++;
        }
    }
    
    return max_len;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;

    cin>>n>>k;

    vector<int> seq(n);
    for(int i = 0; i<n; i++){
        cin>> seq[i];
    }
    cout<<findSubseqLen(seq,k);
}