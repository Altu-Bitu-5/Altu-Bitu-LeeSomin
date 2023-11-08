// 2343.cpp

#include <iostream>
#include <vector>

using namespace std;

int cntBD(int bd_size, vector<int>&video){
    // 블루레이 크기에 대해 각 영상을 저장할 때 나오는 디스크의 갯수를 리턴하는 함수
    int cnt = 1;
    int curr_size = bd_size;
    for(int i = 0; i<video.size(); i++){
        if(curr_size<video[i]){
            // 저장할 영상의 용량이 현재 디스크의 남은 용량보다 적을 때
            // 새로운 디스크를 사용하므로 curr_size를 처음 용량으로 초기화
            cnt++;
            curr_size = bd_size;
        }
        // 현재 영상을 저장 후 남은 용량 갱신
        curr_size-=video[i];
    }
    // 블루레이 디스크 갯수 리턴
    return cnt;
}

int binarySearch(int max_len, int m, vector<int>&video){
    // 디스크의 최소 용량은 최대길이 영상의 크기이고(이보다 작으면 저장불가능한 영상이 생김)
    // 최대 용량은 모든 영상 길이의 합임
    int left = max_len;
    int right = 0;
    for(int i = 0; i<video.size(); i++){
        right+=video[i];
    }
    
    while(left<=right){
        int mid = (left+right)/2;
        int bd_cnt = cntBD(mid, video);

        if(bd_cnt>m){
            // 디스크의 갯수가 지정된 갯수보다 많으면
            // 블루레이 용량을 키움
            left = mid+1;
        }
        else{
            // 디스크의 갯수가 지정된 갯수보다 적거나 같으면 
            // 블루레이 용량을 줄임
            right = mid-1;
        }
        
    }

    return left;
}

int main(){
    int m, n;
    int max_len = 1;    // 블루레이의 최소크기를 구하기 위해 정의

    cin>>n>>m;
    vector<int> video(n);

    for( int i = 0; i<n; i++){
        cin>>video[i];
        max_len = max(max_len,video[i]);
    }

    cout<<binarySearch(max_len,m,video);
}
