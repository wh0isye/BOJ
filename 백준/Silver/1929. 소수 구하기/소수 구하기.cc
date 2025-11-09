#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void prime(int M, int N) {
    vector<bool> prime(N + 1, true);
    prime[0] = false;
    prime[1] = false;

    for (int i = 2; i <= sqrt(N); i++) {
        if (prime[i]) {
            for (int j = 2 * i; j <= N; j += i) {
                prime[j] = false;
            }
        }
    }

    for (int i = M; i <= N; i++) {
        if (prime[i]) {
            cout << i << '\n';
        }
    }
}

int main() {
    int M, N;
    cin >> M >> N;

    prime(M, N);
}