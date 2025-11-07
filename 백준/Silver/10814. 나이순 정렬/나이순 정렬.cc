#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool cmp(pair<int, string> a, pair<int, string> b) {
    return a.first < b.first;
}

int main() {
    int N;
    cin >> N;

    vector<pair<int, string>> user;
    for (int i = 0; i < N; i++) {
        int age;
        string name;
        cin >> age >> name;

        user.push_back(make_pair(age, name));
    }

    stable_sort(user.begin(), user.end(), cmp);

    for (int i = 0; i < user.size(); i++) {
        cout << user[i].first << " " << user[i].second << '\n';
    }
}