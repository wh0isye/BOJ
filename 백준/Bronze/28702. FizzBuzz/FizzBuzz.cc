#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<string> v;
    for (int i = 0; i < 3; i++) {
        string str;
        cin >> str;
        v.push_back(str);
    }

    int number{0};
    int index{-1};

    for (int i = 0; i < v.size(); i++) {
        if (v[i] == "Fizz") {
            // 3의 배수
            continue;
        } else if (v[i] == "Buzz") {
            // 5의 배수
            continue;
        } else if (v[i] == "FizzBuzz") {
            // 15의 배수
            continue;
        } else {
            // 숫자
            number = stoi(v[i]);
            index = i;
            break;
        }
    }

    if (index == 0) {
        number += 3;
    } else if (index == 1) {
        number += 2;
    } else if (index == 2) {
        number += 1;
    }

    if (number % 3 == 0) {
        if (number % 5 == 0) {
            cout << "FizzBuzz" << '\n';
        } else {
            cout << "Fizz" << '\n';
        }
    } else if (number % 5 == 0) {
        cout << "Buzz" << '\n';
    } else {
        cout << number << '\n';
    }
}