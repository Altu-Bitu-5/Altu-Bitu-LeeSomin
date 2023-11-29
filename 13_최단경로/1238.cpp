// 1238.cpp

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int,int> ci;
const int INF = 2e5;


vector <int> dijkstra(int start, int v, vector<vector<ci>> &graph){
    // 다익스트라를 통해 각 정점까지의 최단경로 탐색
    vector<int> dist(v+1,INF);
    priority_queue<ci,vector<ci>,greater<>> pq;

    dist[start] = 0;
    pq.push({0,start});

    while(!pq.empty()){
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(weight>dist[node]){
            // edge의 길이가 이미 최단경로보다 길 경우
            continue;
        }

        for(int i = 0; i<graph[node].size();i++){

            int next_node = graph[node][i].second;
            int next_weight = weight+graph[node][i].first;

            if(next_weight<dist[next_node]){
                // dist 갱신
                dist[next_node] = next_weight;
                pq.push({next_weight, next_node});
            }
        }
    }
    return dist;
}

int main(){
    int n, m, x;
    cin>>n>>m>>x;

    int a, b, d;
    vector<vector<ci>> graph_to(n+1,vector<ci>(0));

    for(int i = 0; i<m; i++){
        cin>> a >> b >> d;
        // a노드에 d 길이의 b까지의 경로 추가
        graph_to[a].push_back({d,b});
    }

    vector<int> to_dijk = dijkstra(x,n,graph_to);   // x까지 갈 떄의 최단경로
    vector<int> from_dijk(n+1);
    
    for(int k = 1; k<n+1; k++){
        // 돌아오는 길을 node마다 다익스트라로 돌려줌
        if( k == x){
            continue;
        }
        from_dijk[k] = dijkstra(k,n,graph_to)[x];
    }

    int max_dist = 0;
    int sum;

    for(int j = 1; j<n+1; j++){
        // 제일 오래 걸리는 시간 구하기
        sum = to_dijk[j]+from_dijk[j];
        if(sum>max_dist){
            max_dist = sum;
        }
    }

    cout<<max_dist;
}