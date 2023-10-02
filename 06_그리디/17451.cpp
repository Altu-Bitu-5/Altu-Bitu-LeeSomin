// 17451.cpp

#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    long long spd, k;
    cin >> n;

    // 각 행성별로 필요한 속도 입력
    vector<long long> planet(n);
    for (int i = 0; i < n; i++){
        cin >> planet[i];
    }

    // 벡터의 맨 뒤에서부터 속도를 올려서 구한다. 
    spd = planet[n-1];
    for (int j = n-2; j >= 0; j--){
        // 행성 j에 필요한 속도가 현재 속도보다 크면 
        // 행성 j에 필요한 속도로 현재 속도 갱신
        if (planet[j] >= spd){
            spd = planet[j];
        }

        // 현재 속도가 행성 j에 필요한 속도보다 클 때,
        // 현재 속도보다 큰 행성 j 속도의 배수의 최솟값으로 갱신 
        else if(spd%planet[j]!=0){
            k = (long long)(spd/planet[j])+1;
            spd = planet[j] * k;
        }

    }

    // 결과 출력
    cout << spd;

}