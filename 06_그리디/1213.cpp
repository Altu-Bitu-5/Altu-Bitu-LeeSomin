// 1213.cpp

#include <iostream>
#include <vector>

using namespace std;

string getPalindrome(string org){
    string pal;
    int odd=0, odd_idx;
    vector <int> alph(26,0);

    // 각 알파벳의 갯수를 세어줌
    for(int i=0;i<org.size();i++){
        alph[org[i]-'A']++;
    }

    for(int j=0;j<26;j++){
        // 만약 홀수인 문자가 2개 이상이면 팰린드롬을 만드는 것이 불가능함
        if(alph[j]%2){
            odd++;
            odd_idx = j;
        }
        if(odd>1){
            return "I'm Sorry Hansoo";
        }

        // 각 알파벳의 갯수의 반절만큼 팰린드롬에 push 해줌
        // 홀수라면 2로 나누어 내림한 수만큼 push
        for(int n = 0;n<alph[j]/2;n++){
            pal.push_back(j+'A');
        }
    }

    int pal_size = pal.size();
    
    // 원래의 문자열의 길이가 홀수라면
    // 홀수갯수인 알파벳을 팰린드롬에 push 해줌
    // 이떄, 가운데 알파벳은 다음 for문에서 추가해줄 길이에서 제외
    if(org.size()%2){
        pal.push_back(odd_idx+'A');
    }

    // 팰린드롬의 전반부의 역순으로 알파벳 push
    for(int k = pal_size-1; k>=0; k--){
        pal.push_back(pal[k]);
    }

    return pal;

}

int main(){
    string org,pal;
    cin>>org;

    cout<<getPalindrome(org);


}