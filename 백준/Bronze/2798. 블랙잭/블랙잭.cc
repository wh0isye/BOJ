#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;  // N: 카드의 개수, M: 목표 합
    cin >> N >> M;

    vector<int> card(N);
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        card[i] = num;
    }

    vector<int> result;
    for (int i = 0; i < N - 2; i++) {
        int a = card[i];
        for (int j = i + 1; j < N - 1; j++) {
            int b = card[j];
            for (int k = j + 1; k < N; k++) {
                int c = card[k];
                int sum = (a + b + c) - M;
                result.push_back(sum);
            }
        }
    }

    sort(result.begin(), result.end());
    for (int i = result.size() - 1; i > 0; i--) {
        if (result[i] <= 0) {
            cout << result[i] + M << endl;
            break;
        }
    }
}