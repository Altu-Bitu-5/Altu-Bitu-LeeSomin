// 2531.cpp
#include <iostream>
#include <vector>

using namespace std;

//슬라이딩 윈도우 사용 
int sushi(vector<int> trail, int d, int k, int c){
    int cnt = 1, max_cnt = 1;
    int l = 0, r = 0, r_ind;
    vector<int> sushi_cnt (d+1,0);
    sushi_cnt[c]++;

    while(l<trail.size()){
        // 윈도우의 왼쪽 끝이 회전레일의 맨 오른쪽 값까지 갔을 떄 모든 조합을 탐색한 것임
        if(r-l == k){
            // 윈도우 사이즈가 지정된 사이즈보다 작을 경우 왼쪽 포인터 움직이지 않음
            if(sushi_cnt[trail[l]] == 1){
                // 윈도우를 움직였을 때 한 종류의 초밥이 제외된 경우
                cnt--;
            }
            // 왼쪽 값 제외하고 윈도우 오른쪽으로 움직임
            sushi_cnt[trail[l]]--;
            l++;
        }

        r_ind = r%trail.size();
        if(sushi_cnt[trail[r_ind]] == 0){
            // 윈도우를 움직였을 때 새로운 종류의 초밥이 추가된 경우
            cnt++;
        }
        // 오른쪽 값 추가하고 윈도우 오른쪽으로 움직임
        sushi_cnt[trail[r_ind]]++;
        r++;

        // 종류의 최댓값 갱신
        if(cnt > max_cnt){
            max_cnt = cnt;
        }

    }
    return max_cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, d, k, c;
    cin>> n>> d>> k>> c;

    vector<int> trail (n);

    for(int i = 0; i<n; i++){
        cin>>trail[i];
    }
    cout<<sushi(trail, d, k, c);
}