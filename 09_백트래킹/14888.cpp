// 14888.cpp

#include <iostream>
#include <vector>

using namespace std;

vector<int> num;
// 0: + , 1: -, 2: *, 3: /
vector<int> oper(4);

//max_num과 min_num을 각각 출력 최솟값과 최댓값으로 초기화
int max_num = -1000000000;
int min_num = 1000000000;

int calcNum (int opr, int pos, int ans){
    // 연산기호에 따른 계산 결과 리턴
    switch (opr)
    {
    case 0:
        ans = ans+num[pos+1];
        break;
    case 1:
        ans = ans-num[pos+1];
        break;
    case 2:
        ans = ans*num[pos+1];
        break;
    case 3:
        ans = int(ans/num[pos+1]);
        break;
    default:
        break;
    }
    return ans;
}

void putOperator(int ans, int pos){
    // 연산자를 모두 배치했을 시 max와 min값 갱신 후 리턴
    if(pos==num.size()-1){
        max_num = max(ans,max_num);
        min_num = min(ans,min_num);
        return;
    }

    // 연산자 사용 시 사용횟수만큼 oper[i]차감, 재귀리턴 후 다시 돌려놓음
    for(int i = 0; i<4; i++){
        if(oper[i]>0){
            oper[i]--;
            putOperator(calcNum(i,pos,ans),pos+1);
            oper[i]++;
        }
        
    }
}

int main(){
    int n, tmp;
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>tmp;
        num.push_back(tmp);
    }
    for(int j = 0; j<4; j++){
        cin>>oper[j];
    }

    putOperator(num[0],0);
    cout<<max_num<<'\n'<<min_num;

}