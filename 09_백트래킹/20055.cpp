// 20055.cpp

#include <iostream>
#include <vector>

using namespace std;

int robotBelt(int n, int k, vector <int> belt){
    int on = 0, off = n-1;
    int curr, next;
    int cnt = 0, result = 0;
    vector <bool> is_robot(2*n,false);

    while(cnt<k){
        result++;
        // 벨트 회전
        on = (on+(2*n-1))%(2*n);
        off= (off+(2*n-1))%(2*n);

        // 회전 후 내리는 위치 도달한 로봇 내림
        is_robot[off]=false;

        for(int i = 1; i<n; i++){
            // on과 off의 반대편 레일에는 로봇이 있을 수 없음
            // 따라서 off-1 위치가 가장 먼저 올린 로봇
            curr = (off-i+2*n)%(2*n);
            next = (off-i+1+2*n)%(2*n);
            if(is_robot[curr] && !is_robot[next] && belt[next]>0){
                // 현재 칸에 로봇이 있고 다음 칸이 내구도가 있는 상태에서 비어있으면
                // 로봇 옮기고 다음 칸 내구도 줄임
                is_robot[curr] = false;
                belt[next]--;
                if(next != off){
                    // 다음칸으로 로봇 옮김
                    // 내리는 위치에 도달하면 로봇 내리므로 true로 바꿔줄 필요 X
                    is_robot[next] = true;
                }
                if(belt[next]==0){
                    // 벨트 칸 내구도가 다하면 cnt 올림
                    cnt++;
                }
            }
        }

        // 올리는 위치에 내구도가 남아있고 비어있으면 로봇 올림
        if(!is_robot[on]&&belt[on]>0){
            is_robot[on]=true;
            belt[on]--;
            if(belt[on]==0){
                cnt++;
            }
        }   
    }
    return result;
}

int main(){
    int n, k;
    cin>>n>>k;

    vector <int> belt(2*n);
    for(int i = 0; i<2*n; i++){
        cin>>belt[i];
    }

    cout<<robotBelt(n,k,belt);

}