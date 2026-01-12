#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> tmp;
    for (int i = 0; i < N; i++) {
        int time;
        cin >> time;

        tmp.push_back(time);
    }

    sort(tmp.begin(), tmp.end());

    int result{0};
    for (int i = N; i > 0; i--) {
        result += i * tmp[N - i];
    }

    cout << result << '\n';
}