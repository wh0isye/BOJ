#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M;  // 수행할 연산의 수
    cin >> M;

    set<int> s;

    while (M--) {
        string cmd;
        cin >> cmd;

        if (cmd == "add") {
            int N;
            cin >> N;

            s.insert(N);
        } else if (cmd == "remove") {
            int N;
            cin >> N;

            s.erase(N);
        } else if (cmd == "check") {
            int N;
            cin >> N;

            // N이 존재하면 1, 존재하지 않으면 0 출력
            if (s.count(N)) {
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        } else if (cmd == "toggle") {
            int N;
            cin >> N;

            // N이 존재하면 지우고, 존재하지 않으면 집합에 삽입
            if (s.count(N)) {
                s.erase(N);
            } else {
                s.insert(N);
            }
        } else if (cmd == "all") {
            s = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
        } else if (cmd == "empty") {
            s = {};
        }
    }
}