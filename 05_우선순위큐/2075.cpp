// 2075.cpp

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    //입출력 동기화 해제
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, tmp;
    cin >> n;

    // min heap 생성
    priority_queue<int,vector<int>,greater<int>> que;
    for (int a = 0; a < n; a++) {
        // 첫 n개는 힙에 넣어 크기가 n인 힙을 만들어줌
        cin>>tmp;
        que.push(tmp);
    }

    for (int i = 0; i<n-1; i++) {
        // 나머지 입력에 대해
        // 이미 힙에 들어가있는 값들 중 최솟값보다 클 경우 
        // 최솟값을 pop 한 후 입력값을 push 해서 상위 n개의 값을 저장
        for (int j = 0; j < n; j++) {
            cin >> tmp;
            if(que.top()<tmp){
                que.push(tmp);
                que.pop();
            }
        }
    }
    // 상위 값 n개로 이루어진 min heap에서 top노드는 n번째로 큰 수임
    cout << que.top()<<endl;
}