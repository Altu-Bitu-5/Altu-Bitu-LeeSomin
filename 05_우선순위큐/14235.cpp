// 14235.cpp

#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n, a, gift;
    priority_queue <int> que;   
    //가치가 가장 큰 순서로 선물을 줘야하므로 max heap 사용

    cin>>n;
    for (int i = 0; i<n; i++){
        cin>>a;
        // a값이 0일 때 어린이에게 선물을 줌
        if(a==0){
            if(que.empty()){
                // 큐가 비어있을 때 -1 출력
                cout<<-1<<'\n';
            }
            else{
                // heap의 맨 위에서 가치가 가장 높은 선물 출력
                cout<<que.top()<<'\n';
                que.pop();
            }
        }
        else{
            for(int j = 0; j<a; j++){
                // 거점에서 a개의 선물을 우선순위 큐에 넣음
                cin>>gift;
                que.push(gift);
            }
        }
    }
    

}