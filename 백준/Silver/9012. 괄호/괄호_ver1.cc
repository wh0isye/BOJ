#include <iostream>
#include <stack>
using namespace std;

bool isVPS(string str) {
    // 입력된 괄호의 개수가 홀수일 때, 무조건 VPS 아님
    // ) 로 시작할 때, 무조건 VPS 아님
    // ( 로 끝날 때, 무조건 VPS 아님
    if (str.length() % 2) {
        return false;
    } else if (str[0] == ')') {
        return false;
    } else if (str[str.size() - 1] == '(') {
        return false;
    }

    stack<char> tmp;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            tmp.push('(');
        } else if (str[i] == ')') {
            if (tmp.empty()) {
                return false;
            }
            tmp.pop();
        }
    }

    if (!tmp.empty()) {
        return false;
    } else {
        return true;
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        string str;
        cin >> str;

        if (isVPS(str)) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
}