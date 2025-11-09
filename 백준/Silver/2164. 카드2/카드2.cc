#include <iostream>
#include <queue>

using namespace std;

int main() {
    int N;
    cin >> N;

    // 기본 카드 세팅
    queue<int> q;
    for (int i = 0; i < N; i++) {
        q.push(i + 1);
    }

    // 규칙 적용
    while (q.size() != 1) {
        if (q.size() == 1) {
            break;
        } else {
            q.pop();
        }

        if (q.size() == 1) {
            break;
        } else {
            int tmp = q.front();
            q.pop();
            q.push(tmp);
        }
    }

    cout << q.front() << '\n';
}