// 4963.cpp

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int island(vector<vector<int>> map){
    int cnt = 0;
    int tmp_r, tmp_c;
    vector<vector<int>> visited(map.size(),vector<int>(map[0].size(),0));   // 방문 확인용 벡터
    stack<pair<int,int>> stk;   // DFS 탐색용 스택
    
    // 각 칸에 대해 탐색
    for(int i = 0; i<map.size(); i++){
        for(int j = 0; j<map[0].size(); j++){
            // 이미 방문한 땅이거나 해당 칸이 바다면 탐색을 하지 않음
            if(visited[i][j]||map[i][j]==0){
                continue;
            }

            // 스택에 첫 노드를 넣고 땅의 count 값을 올림
            cnt++;
            visited[i][j] = 1;
            stk.push({i,j});
            tmp_r = i;
            tmp_c = j;
            while(!stk.empty()){
                // 스택 맨 위의 노드를 pop하고 주변 8방위의 자식노드를 push하여 DFS를 구현한다.
                tmp_r = stk.top().first;
                tmp_c = stk.top().second;
                stk.pop();

                // 좌상
                if(tmp_r>0 && tmp_c>0 && !visited[tmp_r-1][tmp_c-1] && map[tmp_r-1][tmp_c-1]==1){
                    stk.push({tmp_r-1,tmp_c-1});
                    visited[tmp_r-1][tmp_c-1]=1;
                }

                // 상
                if(tmp_r>0 && !visited[tmp_r-1][tmp_c] && map[tmp_r-1][tmp_c]==1){
                    stk.push({tmp_r-1,tmp_c});
                    visited[tmp_r-1][tmp_c]=1;
                }

                // 우상
                if(tmp_r>0 && tmp_c<map[0].size()-1 && !visited[tmp_r-1][tmp_c+1] && map[tmp_r-1][tmp_c+1]==1){
                    stk.push({tmp_r-1,tmp_c+1});
                    visited[tmp_r-1][tmp_c+1]=1;
                }

                // 좌
                if(tmp_c>0 && !visited[tmp_r][tmp_c-1] && map[tmp_r][tmp_c-1]==1){
                    stk.push({tmp_r,tmp_c-1});
                    visited[tmp_r][tmp_c-1]=1;
                }

                // 우
                if(tmp_c<map[0].size()-1 && !visited[tmp_r][tmp_c+1] && map[tmp_r][tmp_c+1]==1){
                    stk.push({tmp_r,tmp_c+1});
                    visited[tmp_r][tmp_c+1]=1;
                }

                // 좌하
                if(tmp_r<map.size()-1 && tmp_c>0 && !visited[tmp_r+1][tmp_c-1] && map[tmp_r+1][tmp_c-1]==1){
                    stk.push({tmp_r+1,tmp_c-1});
                    visited[tmp_r+1][tmp_c-1]=1;
                }

                // 하
                if(tmp_r<map.size()-1 && !visited[tmp_r+1][tmp_c] && map[tmp_r+1][tmp_c]==1){
                    stk.push({tmp_r+1,tmp_c});
                    visited[tmp_r+1][tmp_c]=1;
                }
                

                // 우하
                if(tmp_r<map.size()-1 && tmp_c<map[0].size()-1 && !visited[tmp_r+1][tmp_c+1] && map[tmp_r+1][tmp_c+1]==1){
                    stk.push({tmp_r+1,tmp_c+1});
                    visited[tmp_r+1][tmp_c+1]=1;
                }

                
            }

        }
    }
    return cnt;
}

int main(){
    // 입출력 동기화 해제
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int w, h;
    while(true){
        cin>>w>>h;
        // 0 0 이 들어올 경우 루프 종료
        if(w==0 && h==0){
            break;
        }

        // 입력받은 너비와 높이로 지도 벡터를 만든다
        vector<vector<int>> map(h,vector<int>(w));

        for(int i = 0; i<h; i++){
            for(int j = 0; j<w; j++){
                cin>>map[i][j];
            }
        }

        cout<<island(map)<<'\n';
    }


}