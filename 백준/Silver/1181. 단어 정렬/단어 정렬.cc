#include <iostream>
#include <set>

using namespace std;

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

    set<string, compare> voca;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        voca.insert(str);
    }

    for (const auto& s : voca) {
        cout << s << '\n';
    }
}