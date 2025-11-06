#include <iostream>
#include <stack>

using namespace std;

int main() {
    while (1) {
        string N;
        cin >> N;

        if (N == "0") {
            break;
        }

        stack<char> s;
        for (int i = 0; i < N.size(); i++) {
            s.push(N[i]);
        }

        int count{0};
        for (int i = 0; i < N.size(); i++) {
            if (N[i] == s.top()) {
                count++;
                s.pop();
            }
        }

        if (count == N.size()) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
}