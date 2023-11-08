// 10815.cpp

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(int key, int n, vector<int>& card){
    int left = 0, right = n-1, mid;

    while(left<=right){
        // 이분탐색을 이용해 키 값이 존재하는지 탐색
        mid = (left+right)/2;
        if(card[mid]==key){
            return 1;
        }
        else if(key<card[mid]){
            right = mid-1;
        }
        else{
            left = mid+1;
        }
    }

    return 0;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, tmp;
    cin>>n;
    vector<int> card(n);

    for(int i = 0; i<n; i++){
        cin>>card[i];
    }

    // 이분탐색을 위해 카드 정렬
    sort(card.begin(),card.end());
    
    cin>>m;
    for(int j = 0; j<m; j++){
        // 각 입력에 대해 가지고 있는 카드인지 판별
        cin>>tmp;
        cout<<binarySearch(tmp,n,card)<<' ';
    }
}