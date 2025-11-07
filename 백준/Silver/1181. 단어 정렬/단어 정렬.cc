// 참고
// compare 함수: https://mojing.tistory.com/entry/C-STL-sort-함수-사용법
// compare 함수: https://swblossom.tistory.com/46
// set 원소 출력: https://retn0.tistory.com/5
#include <iostream>
#include <set>

using namespace std;

// compare 함수 작성법을 잘 몰랐음 - 블로그 참고
struct compare {
    bool operator()(string a, string b) const {
        if (a.size() != b.size()) {
            return a.size() < b.size();
        } else {
            return a < b;
        }
    }
};

int main() {
    int N;
    cin >> N;

    // 중복 없음이라는 조건으로 set을 써야 한다는 것은 생각
    set<string, compare> voca;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        voca.insert(str);
    }

    for (const auto& s : voca) {
        cout << s << '\n';
    }
    // 잘 몰랐음 - 블로그 참고
    // 처음에는 아래와 같이 작성
    // for (int i = 0; i < voca.size(); i++) {
    //     cout << voca[i] << '\n';
    // }
}