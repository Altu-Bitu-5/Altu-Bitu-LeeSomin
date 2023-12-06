// 15685.cpp

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 우 상 좌 하 
vector <int> dir_x = {1,0,-1,0};
vector<int> dir_y = {0,-1,0,1};

// 보드
vector <vector<int>> board (101,vector<int>(101,0));

using namespace std;

int countBox(){
    // 1*1 정사각형의 네 꼭짓점이 모두 드래곤 커브의 점인 사각형 카운트
    int cnt = 0;

    for(int i = 0; i<board.size()-1;i++){
        for(int j = 0; j<board.size()-1;j++){
            if(board[i][j] && board[i+1][j] && board[i][j+1] && board[i+1][j+1]){
                cnt++;
            }
        }
    }
    return cnt;
}

void dragonCurve(int x, int y, int d, int g){
    int curr_dir;
    pair<int,int> endpos = {x+dir_x[d],y+dir_y[d]};
    vector<int> directions = {d};
    // 0번 턴 미리 진행
    board[y][x]++;
    board[endpos.second][endpos.first]++;

    for(int i = 0; i<g; i++){
        // 역순으로 방향에 +1을 해서 움직이면 90도 회전한 모양이 그려짐
        for(int j = directions.size()-1; j>=0; j--){
            // 방향 업데이트 후 저장 
            curr_dir = (directions[j]+1)%4;
            directions.push_back(curr_dir);
            
            // 끝 점 이동
            endpos.first = endpos.first+dir_x[curr_dir];
            endpos.second = endpos.second+dir_y[curr_dir];
            // 방문 체크
            board[endpos.second][endpos.first]++;
            
        }
    }
}


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    int x, y, d, g;

    cin>> n;
    for(int i = 0; i < n; i++){
        cin>> x >> y >> d >> g;
        dragonCurve(x,y,d,g);
    }
    cout<<countBox();

}