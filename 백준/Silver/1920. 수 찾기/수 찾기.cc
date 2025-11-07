#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    unordered_set<int> number;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        number.insert(num);
    }

    int M;
    cin >> M;

    for (int i = 0; i < M; i++) {
        int test;
        cin >> test;

        // set STL 공부하기
        if (number.find(test) != number.end()) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
}