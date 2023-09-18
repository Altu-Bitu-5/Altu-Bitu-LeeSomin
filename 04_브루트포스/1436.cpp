// 1436.cpp

#include <iostream>

using namespace std;

int getMovieNum(int n){
    int movie_num = 665, count = 0, check_num = 0;
    // 브루트포스를 이용해 모든 수에 대하여 666이 들어가는 수인지 검사한다.
    while(count<n){
        movie_num++;
        check_num = movie_num;
        while(check_num/100>=1){
            // 세자릿수 이상일 때 맨 끝자리가 666이면 count를 올리고
            // 아니면 10을 나눠 다음 3자리를 검사한다.
            if(check_num%1000==666){
                count++;
                break;
            }
            check_num/=10;
        }
    }
    return movie_num;

}

int main(){
    int n, result;
    cin>>n;
    result = getMovieNum(n);
    cout<<result;
}