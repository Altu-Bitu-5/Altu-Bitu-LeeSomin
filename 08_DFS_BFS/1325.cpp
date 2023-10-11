// 1325.cpp

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> hack(vector<vector<int>> com){
    vector<int> result;
    vector<int> visit(com.size(),0);
    stack <int> stk;
    int max = 0, cnt = 0, top;

    // DFS로 탐색 후 해킹 가능 컴퓨터 수 Max랑 비교 후 저장
    for(int i = 1; i<com.size(); i++){

        cnt = 0;
        // 스택에 시작 노드 push 후 방문 체크
        stk.push(i);
        visit[i]=1;
        while(!stk.empty()){
            // top 노드가 해킹할 수 있는 컴퓨터를 DFS로 탐색
            top = stk.top();
            stk.pop();
            for(int j = 0; j<com[top].size();j++){
                if(!visit[com[top][j]]){
                    visit[com[top][j]] = 1;
                    stk.push(com[top][j]);
                    cnt++;
                }
            }
        }

        // visit 벡터 재사용 위해 초기화
        for(int k = 0; k < visit.size();k++){
            visit[k] = 0;
        }

        // 해킹할 수 있는 컴퓨터 수가 max보다 많으면 
        // 결과벡터 클리어, max 갱신 후 컴퓨터 번호 push
        // max와 같으면 갱신 없이 push
        if(cnt<max){
            continue;
        }
        else if(cnt>max){
            result.clear();
            max = cnt;
        }

        result.push_back(i);

        
    }

    return result;
}

int main(){
    int n, m;
    int a, b;
    vector<int> result;
    cin>>n>>m;

    vector <vector<int>> com(n+1,vector<int>());
    for(int i = 0; i<m; i++){
        // b에서 a를 해킹할 수 있음(a가 b를 신뢰함)
        cin>> a >> b;
        com[b].push_back(a);
    }

    result = hack(com);
    // 오름차순 출력을 위해 sort해줌
    sort(result.begin(),result.end());
    for(int j = 0; j<result.size(); j++){
        cout<<result[j]<<' ';
    }

}