// 3079.cpp

#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

ull cntPeople(ull tot_time, vector<ull>&port){
    // 총 시간을 매개변수로 받고 
    // 그 시간에 각 창구가 처리할 수 있는 인원수를 리턴함
    ull cnt = 0;
    for(int i = 0; i<port.size(); i++){
        cnt+=int(tot_time/port[i]);
    }
    return cnt;
}

ull binarySearch(ull left, ull right, int people, vector<ull>&port){
    // 이진탐색으로 주어진 인원을 처리할 수 있는 최소 시간을 구함
    while(left<=right){
        ull mid = (left+right)/2;
        ull people_cnt = cntPeople(mid, port);

        if(people_cnt>=people){
            // 처리할 수 있는 인원이 제시된 인원 이상이면 표본 상한을 줄임
            right = mid-1;
        }
        else{
            // 처리할 수 있는 인원이 제시된 인원 미만이면 표본 하한을 올림
            left = mid+1;
        }
    }
    return left;
}


int main(){
    int n, m;
    ull min_time = 1000000000;  // 이분탐색의 최소시간과 최대시간을 구하기 위해 정의
    
    cin>>n>>m;
    
    vector <ull> port(n);

    for (int i = 0; i<n; i++){
        cin>>port[i];
        min_time=min(min_time,port[i]);
    }

    cout<<binarySearch(min_time,min_time*m,m,port);
}