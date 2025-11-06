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
        // 2 1 5와 같은 경우를 위한 코드
        if (num % (A - B) == 0) {
            count += num / (A - B);
            cout << count << endl;
        }
        // 5 2 10과 같은 경우를 위한 코드
        else {
            count++;
            count += num / (A - B);
            cout << count << endl;
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