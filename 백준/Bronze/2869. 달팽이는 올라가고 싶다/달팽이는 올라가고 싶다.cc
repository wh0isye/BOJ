#include <iostream>
using namespace std;

int main() {
    int A, B, V;
    cin >> A >> B >> V;

    int count{1};
    int num = V - A;

    if (num <= 0) {
        cout << count << endl;
    } else {
        if (num / (A - B) == 0) {
            count++;
            cout << count << endl;
        } else {
            if (num % (A - B) == 0) {
                count += num / (A - B);
                cout << count << endl;
            } else {
                count++;
                count += num / (A - B);
                cout << count << endl;
            }
        }
    }
}

// 시도1(시간 초과)

// #include <iostream>

// using namespace std;

// int main() {
//     ios_base ::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     int A, B, V;
//     cin >> A >> B >> V;

//     int num{0};
//     int count{0};
//     while (num != V) {
//         num += A;
//         if (num == V) {
//             count++;
//             break;
//         }
//         num -= B;
//         count++;
//     }

//     cout << count << '\n';
// }