#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

struct cmp
{
    // 우선순위 큐를 위한 비교함수, processing time을 비교한다.
    bool operator()(pair<int,int> a , pair<int,int> b){
    return a.second>b.second;
    }
};

bool compare(vector<int> a, vector<int> b){
    // 처음 프로세스가 들어온 순서에 따라 정렬하기 위한 벡터 비교 함수
    return a[0]<b[0];
}

int solution(vector<vector<int>> jobs) {
    // 들어온 프로세스를 요청시간순으로 정렬
    sort(jobs.begin(),jobs.end(),compare);

    // timestamp를 가장 먼저 들어온 작업의 요청시간으로 초기화
    int timestamp = jobs[0][0], pid = 0, ptime = 0, poped=0;
    // 대기중인 프로세스들의 우선순위 큐
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> plist;
    
    
    // 프로세스 큐에서 pop 된 작업의 수가 요청된 작업의 수와 같을 때까지 실행
    while(poped!=jobs.size()){
        // 작업중이 아니어서 큐가 비어있거나, 요청이 들어온 시간이 지날 때 큐에 작업 push
        while(pid<jobs.size()&&(timestamp>=jobs[pid][0] || plist.empty())){
            plist.push(make_pair(jobs[pid][0],jobs[pid][1]));
            pid++;
        }
        
        // 작업중이 아니었을 때 다음 작업의 요청시간으로 시간 변경
        if(timestamp<plist.top().first){
            timestamp = plist.top().first;
        }
        // 작업 수행
        timestamp += plist.top().second;
        ptime += (timestamp - plist.top().first);
        plist.pop();
        poped++;
        
    }

    // 작업시간의 합을 작업의 수로 나누어 리턴
    return int(ptime/jobs.size());
}