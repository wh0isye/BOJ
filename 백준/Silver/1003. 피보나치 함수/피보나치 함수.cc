#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    vector<pair<int, int>> countResult(40, make_pair(0, 0));
    countResult[0] = (make_pair(1, 0));
    countResult[1] = (make_pair(0, 1));

    while (T--) {
        int N;
        cin >> N;

        for (int i = 2; i <= N; i++) {
            int zero = countResult[i - 1].first + countResult[i - 2].first;
            int one = countResult[i - 1].second + countResult[i - 2].second;

            countResult[i] = make_pair(zero, one);
        }

        cout << countResult[N].first << " " << countResult[N].second << '\n';
    }
}