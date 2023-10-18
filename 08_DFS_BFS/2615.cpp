//2615.cpp

#include <iostream>
#include <vector>

using namespace std;

// 결과값 전달을 위한 구조체
typedef struct gametoken{
    int winner;
    int row;
    int col;
};

gametoken omok(vector<vector<int>> board){
    gametoken curr;
    int cnt = 0;
    int tmp_r, tmp_c;

    // 각 격자에 대하여 4방향의 오목 여부를 탐색
    // 왼쪽부터 탐색하기 위해 가장 바깥의 for문을 j로 해주었음
    // 승패가 결정되지 않았으면 winner에 0 값 넣어서 리턴
    for(int j =0; j<19; j++){
        for (int i =0; i<19; i++){
            curr.winner = board[i][j];
            curr.row = i;
            curr.col = j;
            
            // 격자가 비어있으면 continue
            if(curr.winner == 0){
                continue;
            }
            // direction: -
            tmp_c = j;
            cnt = 0;
            while(tmp_c<19){
                // 현재 탐색하는 방향의 이전 격자에 같은 색의 돌이 놓여있으면 
                // 이미 탐색 한 경우이므로 건너뛴다. 
                if(j>0&&board[i][j-1]==curr.winner){
                    break;
                }
                if(board[i][tmp_c]!=curr.winner){
                    break;
                }
                tmp_c++;
                cnt++;
            }

            if(cnt == 5){
                // 오목인 경우 return
                return curr;
            }

            // direction: |
            tmp_r = i;
            cnt = 0;
            while(tmp_r<19){
                if(i>0&&board[i-1][j]==curr.winner){
                    break;
                }
                if(board[tmp_r][j]!=curr.winner){
                    break;
                }
                tmp_r++;
                cnt++;
            }

            if(cnt == 5){
                return curr;
            }

            // direction: /
            tmp_r = i;
            tmp_c = j;
            cnt = 0;
            while(0<=tmp_r && tmp_c<19){
                if(i<18&&j>0&&board[i+1][j-1]==curr.winner){
                    break;
                }
                if(board[tmp_r][tmp_c]!=curr.winner){
                    break;
                }
                tmp_r--;
                tmp_c++;
                cnt++;
            }

            if(cnt == 5){
                return curr;
            }

            // direction: '\'
            tmp_r = i;
            tmp_c = j;
            cnt = 0;
            while(tmp_r<19 && tmp_c<19){
                if(i>0&&j>0&&board[i-1][j-1]==curr.winner){
                    break;
                }
                if(board[tmp_r][tmp_c]!=curr.winner){
                    break;
                }
                tmp_r++;
                tmp_c++;
                cnt++;
            }

            if(cnt == 5){
                return curr;
            }


        }
    }

    curr.winner = 0;
    return curr;
}

int main(){
    // 입출력 동기화 해제
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector <vector<int>> board(19,vector<int>(19));
    gametoken result;

    for(int i = 0; i<19; i++){
        for(int j = 0; j<19; j++){
            cin>>board[i][j];
        }
    }

    result = omok(board);
    cout<<result.winner<<'\n';
    if(result.winner!=0){
        // 승자가 있을 때만 출력
        cout<< result.row+1 << ' ' << result.col+1;
    }

}