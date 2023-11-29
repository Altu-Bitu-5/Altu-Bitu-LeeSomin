// 2458.cpp

#include <iostream>
#include <vector>

using namespace std;
const int INF = 5e3;

void floydWarshall(int n, vector<vector<int>> &graph){
    for(int i = 1; i<=n; i++ ){ // 중간
        for(int j = 1; j<=n; j++){  // 출발
            for(int k = 1; k<=n; k++){  // 도착
                int cost = graph[j][i] + graph[i][k];
                graph[j][k] = min(graph[j][k],cost);
            }
        }
    }
}

int main(){
    int n, m;
    cin>>n>>m;

    // 모든 간선 길이 INF로 초기화
    vector<vector<int>> graph(n+1,vector<int>(n+1,INF));

    for(int i = 1; i<=n; i++){
        // 자신 - 자신 거리는 0
        graph[i][i] = 0;
    }

    int a, b;
    for(int j = 0; j<m; j++){
        cin>>a>>b;
        // a->b 연결(거리 1)
        graph[a][b] = 1;

    }

    int cnt = 0;
    // 모든 노드 조합의 최단거리 구하기
    floydWarshall(n,graph);

    for(int k = 1; k<=n; k++ ){
        for(int l = 1; l<=n; l++){
            // k에서 l로 가는 길이나 l에서 k로 가는 길 중 어느것도 없으면
            // k의 키 순서 모름
            if(graph[k][l]==INF && graph[l][k] == INF){
                cnt++;
                break;
            }
        }
    }
    // 키 순서를 모르는 학생 수를 전체 학생 수에서 뻄
    cout<<n-cnt;
}