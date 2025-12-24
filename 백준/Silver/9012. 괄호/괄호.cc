#include <iostream>
#include <vector>
using namespace std;

bool isVPS(string str, vector<char> &tmp) {
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

    int length = tmp.size();
    int left_index;  // ( 인덱스 저장

    // 처음으로 ( 가 나오는 위치 탐색 - 뒤에서부터 탐색하는 것이 효율적이라고 판단
    for (int i = length - 1; i >= 0; i--) {
        if (tmp[i] == '(') {
            left_index = i;

            // ( 가 나오는 위치 이후에 ) 가 나오는 위치 탐색
            for (int j = left_index + 1; j < length; j++) {
                if (tmp[j] == ')') {
                    tmp[i] = -1;  // 처리 완료의 의미
                    tmp[j] = -1;  // 처리 완료의 의미
                    break;
                }
            }
        }
    }

    bool result = true;  // 결과 플래그

    for (int i = 0; i < length; i++) {
        if (tmp[i] == '(' || tmp[i] == ')') {
            result = false;
        }
    }

    return result;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        string str;
        cin >> str;

        vector<char> tmp;
        for (int i = 0; i < str.length(); i++) {
            tmp.push_back(str[i]);
        }

        if (isVPS(str, tmp)) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
}