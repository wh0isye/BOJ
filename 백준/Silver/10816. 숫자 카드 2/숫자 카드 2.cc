// 참고: https://bbeomgeun.tistory.com/18
#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    unordered_map<int, int> m;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        m[num]++;
    }

    int M;
    cin >> M;

    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;

        cout << m[num] << " ";
    }

    cout << "\n";
}

// 잘못된 풀이
// #include <algorithm>
// #include <iostream>
// #include <vector>

// using namespace std;

// int main() {
//     ios_base ::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     int N;
//     cin >> N;

//     vector<int> v;
//     for (int i = 0; i < N; i++) {
//         int num;
//         cin >> num;
//         v.push_back(num);
//     }
//     sort(v.begin(), v.end());

//     int M;
//     cin >> M;

//     vector<int> check;
//     for (int i = 0; i < M; i++) {
//         int num;
//         cin >> num;
//         check.push_back(num);
//     }

//     vector<int> result;
//     for (int i = 0; i < check.size(); i++) {
//         int count{0};
//         for (int j = 0; j < v.size(); j++) {
//             if (check[i] == v[j]) {
//                 count++;
//             }
//         }
//         result.push_back(count);
//     }

//     for (int i = 0; i < result.size(); i++) {
//         cout << result[i] << " ";
//     }

//     cout << "\n";
// }