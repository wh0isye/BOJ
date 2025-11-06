#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int k, n;
        cin >> k;  // 층수
        cin >> n;  // 호수

        vector<int> v(n + 1, 0);  // 층별 정보 저장
        for (int i = 1; i < n + 1; i++) {
            v[i] = i;
        }

        for (int i = 0; i < k; i++) {
            for (int j = 1; j <= n; j++) {
                v[j] += v[j - 1];
            }
        }
        cout << v[n] << endl;
    }
}