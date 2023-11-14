// 16401.cpp

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cntSnack(int snack_len, vector<int>&snack){
    // 만들 수 있는 snack_len 길이의 과자의 갯수를 구하여 리턴
    int cnt = 0;
    for(int i = 0; i<snack.size(); i++){
        if(snack[i]<snack_len){
            // 나누어주어야 하는 과자 길이가 현 과자의 길이보다 길면
            // 나누어줄 수 없으므로 continue
            continue;
        }
        // 현 과자를 주어진 길이로 나누어 그 갯수를 cnt에 더함
        cnt+=(snack[i]/snack_len);
    }
    return cnt;
}

int binarySearch(int left, int right, int target, vector<int>&snack){
    // 이분탐색을 사용해 과자의 최대 길이를 구함
    while(left<=right){
        int mid = (left+right)/2;
        int snack_cnt = cntSnack(mid, snack);

        if(snack_cnt>=target){
            // 과자의 갯수가 아이들의 수 이상일 때 
            // 과자의 길이를 늘림
            left = mid+1;
        }
        else{
            // 과자의 갯수가 아이들의 수보다 적을 때
            // 과자의 길이를 줄임
            right = mid-1;
        }
        
    }

    return right;
}

int main(){
    int m, n;
    cin>>m>>n;
    vector<int> snack(n);
    
    for( int i = 0; i<n; i++){
        cin>>snack[i];
    }
    // 과자 길이의 최댓값을 구하기 위해 sort해줌
    sort(snack.begin(),snack.end());

    cout<<binarySearch(1,snack[snack.size()-1],m,snack);
}