#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;  // 수의 개수
    int M;  // 합을 구해야 하는 횟수
    cin >> N >> M;

    vector<int> v;
    v.push_back(0);  // index를 1부터 처리하기 위해서

    // 숫자 입력
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;

        v.push_back(n);
    }

    // 전체 합
    int sum{0};
    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
    }

    // prefix 합 - DP처럼 처리
    vector<int> prefixSum(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        prefixSum[i] = prefixSum[i - 1] + v[i];
    }

    // suffix 합 - DP처럼 처리
    vector<int> suffixSum(N + 1, 0);
    suffixSum[N] = v[N];
    for (int i = N - 1; i >= 0; i--) {
        suffixSum[i] = suffixSum[i + 1] + v[i];
    }

    for (int k = 0; k < M; k++) {
        int i, j;
        cin >> i >> j;

        int result = sum;
        result = result - prefixSum[i] + v[i];
        result = result - suffixSum[j] + v[j];

        cout << result << '\n';
    }
}