#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    string s;
    cin >> s;

    long long unit = 31;
    long long mod = 1234567891;

    vector<long long> number(N);
    for (int i = 0; i < N; i++) {
        long long tmp{0};
        if (i == 0) {
            tmp = s[i] - 'a' + 1;
        } else {
            tmp = ((s[i] - 'a' + 1) * (unit % mod)) % mod;
            unit = (unit * 31) % mod;
        }
        number[i] = tmp;
    }

    long long sum{0};
    for (int i = 0; i < number.size(); i++) {
        sum += number[i];
        sum %= mod;
    }

    cout << sum << endl;
}

// 13 mod 9 = 4
// 21 mod 9 = 3
// (4*3) mod 9 = 3

// 273 mod 9 = 3

///////////////////////

// 13 mod 9 = 4
// 17 mod 9 = 8
// (8+4) mod 9 = 3

// 30 mod 9 = 3