// 1063.cpp

#include <iostream>
#include <vector>

using namespace std;
typedef pair<char, int> position;

position moveToken(position pos_start, string move){
    // move의 string에 따라 지정된 토큰의 위치를 옮겨
    // 이동 후의 위치를 리턴한다. 
    position pos_finish = pos_start;
    for( int i = 0; i<move.size();i++){
        switch (move[i])
        {
        case 'R':
            pos_finish.first+=1;
            break;
        case 'L':
            pos_finish.first-=1;
            break;
        case 'B':
            pos_finish.second-=1;
            break;
        case 'T':
            pos_finish.second+=1;
            break;
        default:
            break;
        }

        // 좌표의 값이 보드 안에 있으면 다음 loop를 실행
        if('A'<=pos_finish.first && pos_finish.first<='H' && 1<=pos_finish.second && pos_finish.second<=8){
            continue;
        }
        // 좌표의 값이 보드를 벗어나면 처음 위치를 리턴한다. 
        return pos_start;
    }
    return pos_finish;
}

pair <position, position> getPosition(vector<string> moves, position pos_king, position pos_stone){

    for (int i=0; i<moves.size();i++){
        // king이 움직이지 않으면 stone연산도 없다.
        if(moveToken(pos_king,moves[i])==pos_king){
            continue;
        }

        // king이 stone과 같은 위치로 옮겨지고 stone이 움직여도 보드를 벗어나지 않으면
        // stone과 king의 위치 업데이트
        if(moveToken(pos_king,moves[i])==pos_stone){
            if(moveToken(pos_stone,moves[i])==pos_stone){
                continue;
            }
            pos_stone = moveToken(pos_stone,moves[i]);
        }
        pos_king = moveToken(pos_king,moves[i]);
    }
    return make_pair(pos_king,pos_stone);
}

int main(){
    position pos_king, pos_stone;
    int n = 0;
    string init_king, init_stone;

    cin>> init_king >> init_stone>>n;
    // 입력받은 값으로 각각의 위치좌표를 초기화해준다. 
    pos_king = make_pair(init_king[0], init_king[1]-'0');
    pos_stone = make_pair(init_stone[0], init_stone[1]-'0');
    
    // n번 이동명령을 받아 getPosition 실행
    vector <string> moves(n);
    for (int i =0; i<moves.size();i++){
        cin>>moves[i];
    }
    pair <position, position> result = getPosition(moves,pos_king,pos_stone);
    
    // 킹과 돌의 좌표 각각 출력
    cout<<result.first.first<<result.first.second<<'\n';
    cout<<result.second.first<<result.second.second;
}