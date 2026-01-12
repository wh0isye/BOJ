#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int N, M;  // N은 들어보지 못한 사람, M은 보지 못한 사람
    cin >> N >> M;

    set<string> list;

    for (int i = 0; i < N; i++) {
        string name;
        cin >> name;

        list.insert(name);
    }

    int count{0};
    vector<string> result;

    for (int i = 0; i < M; i++) {
        string name;
        cin >> name;

        if (list.count(name)) {
            result.push_back(name);
            count++;
        }
    }

    // 사전 순 정렬, vector<string> result 대신 새로운 set에 저장하는 방법도 있음
    sort(result.begin(), result.end());

    cout << count << '\n';
    for (string name : result) {
        cout << name << '\n';
    }
}