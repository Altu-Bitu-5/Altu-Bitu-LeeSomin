//1655.cpp

#include <iostream>
#include <queue>

using namespace std;

int getMiddle(int num, priority_queue<int>& smaller, priority_queue<int, vector<int>, greater<int>>& bigger) {
    //bigger는 min heap이고 smaller는 maxheap이다.
    // num의 값이 중앙값의 오른쪽 값보다 클 때 bigger에 push, 아니면 smaller에 push
    if (!bigger.empty() && bigger.top() < num) {
        bigger.push(num);
    }
    else {
        smaller.push(num);
    }

    // smaller의 원소가 많을 때 bigger로 옮겨줌
    while (int(smaller.size()-bigger.size()) > 1) {
        bigger.push(smaller.top());
        smaller.pop();
    }
    //bigger의 원소가 많을 때 smaller로 옮겨줌
    while (bigger.size() > smaller.size()) {
        smaller.push(bigger.top());
        bigger.pop();
    }

    // smaller의 root 노드의 값이 중앙값임
    return smaller.top();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, num;
    priority_queue<int, vector<int>, greater<int>> bigger;
    priority_queue<int> smaller;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        cout << getMiddle(num, smaller, bigger) << '\n';
    }


}