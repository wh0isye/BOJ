#include <iostream>
#include <vector>

using namespace std;

int main() {
    string isbn;
    cin >> isbn;

    vector<char> v;
    v.push_back('0');
    for (int i = 0; i < isbn.size(); i++) {
        v.push_back(isbn[i]);
    }

    int sum{0};
    bool check = true;
    for (int i = 1; i < v.size(); i++) {
        if (v[i] == '*') {
            if (i % 2 == 1) {
                check = true;  // 홀수 일때 true
            } else if (i % 2 == 0) {
                check = false;  // 짝수 일때 false
            }
        }
        // 홀수
        else if (i % 2 == 1) {
            sum += (v[i] - '0');
        }
        // 짝수
        else if (i % 2 == 0) {
            sum += 3 * (v[i] - '0');
        }
    }

    int tmp = sum % 10;
    int result = 10 - tmp;
    // check값이 0일때
    if (tmp == 0) {
        cout << tmp << endl;
    } 
    // * 위치가 홀수일때
    else if (check) {
        cout << result << endl;
    } 
    // * 위치가 짝수일때
    else {
        switch (result) {
            case 1:
                cout << 7 << endl;
                break;
            case 2:
                cout << 4 << endl;
                break;
            case 3:
                cout << 1 << endl;
                break;
            case 4:
                cout << 8 << endl;
                break;
            case 5:
                cout << 5 << endl;
                break;
            case 6:
                cout << 2 << endl;
                break;
            case 7:
                cout << 9 << endl;
                break;
            case 8:
                cout << 6 << endl;
                break;
            case 9:
                cout << 3 << endl;
                break;
        }
    }
}