// 18111.cpp

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair <int,int> landGrading(vector<int> land, int b){
    int time=0,lv;
    int get = 0, put = 0, bag = b;
    
    sort(land.begin(), land.end());

    // 땅 높이의 최솟값이 256이거나
    // 최댓값이 0이면 이미 고른 땅이므로 return
    if(land[0]==256){
        return make_pair(0,256);
    }
    else if(land[land.size()-1]==0){
        return make_pair(0,0);
    }

    // 모든 땅 높이에 대해 계산하고 걸리는 최소시간을 return
    for(int l = 0; l<=256; l++){
        bag = b;
        get = 0;
        put = 0;
        
        // 기준 높이보다 높으면 땅을 깎고 인벤토리에 넣음
        // 기준 높이보다 낮으면 인벤토리에서 땅을 꺼내 쌓음
        for(int i = 0; i<land.size(); i++){
            if(land[i]>l){
                get += (land[i]-l);
                bag += (land[i]-l);
            }
            else if(land[i]<l){
                put += (l-land[i]);
                bag -= (l-land[i]);
            }
        }

        // 인벤토리에 남은 땅이 음수면 해당 높이는 불가능함
        if(bag<0){
            continue;
        }

        // 최초 1회이거나 계산한 시간이 현재 time의 값보다 작으면
        // 땅의 높이와 최소 시간 갱신
        if(time == 0 || time>=get*2+put){
            time = get*2+put;
            lv = l;
        }

    }

    return make_pair(time,lv);
}

int main(){
    // 입출력 동기화 해제
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 입력
    int n, m, b;
    cin>>n>>m>>b;
    vector <int> land(n*m);

    for(int i = 0; i<land.size(); i++){
        cin>>land[i];
    }

    // 계산 및 출력
    pair<int,int> result = landGrading(land, b);
    cout<<result.first<<' '<<result.second;
    
}