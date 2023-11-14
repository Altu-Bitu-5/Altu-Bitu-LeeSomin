//14500.cpp

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_sum = 0;
int max_val = 0;

vector<vector<int>> vec;
vector<vector<bool>> visited;

// 방향 벡터
vector<int> dir_y = {-1,1,0,0};
vector<int> dir_x = {0,0,-1,1};


void backtracking(int cnt, int sum, int row, int col){
    // 백트래킹을 이용해 깊이 4의 테트로미노의 합의 최댓값을 구함
    sum+=vec[row][col];
    if(sum+max_val*(4-cnt)<max_sum){
        // 만약 남은 칸에 모두 최댓값이 들어있어도 현재 최대합을 넘지 못할 시 유망하지 않은 노드임
        return;
    }

    if(cnt== 4){
        // 4개의 칸에 대한 탐색을 마쳤다면 최대합을 갱신하고 리턴
        if(sum>max_sum){
            max_sum = sum;
        }
        return;
    }

    for (int i =1; i<4; i++){

        if(0<=row+dir_y[i] && row+dir_y[i]<vec.size() && 0<=col+dir_x[i] && col+dir_x[i]<vec[0].size() && !visited[row+dir_y[i]][col+dir_x[i]]){
            visited[row+dir_y[i]][col+dir_x[i]] = true; // 방문
            backtracking(cnt+1,sum,row+dir_y[i],col+dir_x[i]);  // 재귀 호출
            visited[row+dir_y[i]][col+dir_x[i]] = false;    // 회수
        }
    }
}

void shapeNotDFS(int row, int col){
    // ㅓㅜㅗㅏ 모양에 대해 최대합을 구함
    // 이 모양은 중심칸에 대해 상하좌우 칸을 더한 후 한 칸을 뺀 값들임
    int sum = vec[row][col], cnt = 0;
    vector<int> num;
    for(int i = 0; i<4; i++){
        if(0<=row+dir_y[i] && row+dir_y[i]<vec.size() && 0<=col+dir_x[i] && col+dir_x[i]<vec[0].size()){
            num.push_back(vec[row+dir_y[i]][col+dir_x[i]]);
            sum+=num[cnt];
            cnt++;
        }
    }
    if(cnt<3){
        return;
    }
    if(cnt>3){
        sort(num.begin(),num.end());
        sum-=num[0];
    }
    if(sum>max_sum){
        max_sum = sum;
    }
}



void tetro(){
    // 테트로미노의 최대합 구하기
    for(int i =0; i<vec.size();i++){
        for( int j = 0; j<vec[0].size(); j++){
            // DFS로 구할 수 없는 모양의 합
            shapeNotDFS(i,j);
            // DFS를 이용한 모양의 합
            visited[i][j] = true;
            backtracking(1,0,i,j);
            visited[i][j] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;
    vec = vector <vector<int>> (n,vector<int>(m));
    visited = vector <vector<bool>> (n,vector<bool>(m,false));

    for(int i=0; i<n;i++){
        for(int j=0;j<m;j++){
            cin>>vec[i][j];
            max_val = max(vec[i][j],max_val);
        }
    }

    tetro();
    cout<<max_sum;
}