#include <iostream>
using namespace std;

int main() {
    long long N;
    cin >> N;

    long long sub = 6;
    long long unit = 6;
    int count = 1;  // 처음에 1빼고 시작하기 때문
    // 1을 빼고 시작
    N--;
    while (N > 0) {
        N -= sub;  // N-6 -> N-12 -> N-18 -> N-24 이런식으로 1번 반복을 돌 때마다 올라감
        count++;
        sub = count * unit;
    }

    cout << count << endl;
}