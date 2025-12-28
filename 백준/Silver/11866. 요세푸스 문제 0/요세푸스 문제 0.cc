#include <iostream>
#include <vector>
using namespace std;

void Josephus(int K, vector<int> &tmp, vector<int> &result) {
    int count{0};  // 유효한 값의 탐색 횟수 기록용
    int index{0};  // 마지막 인덱스

    while (result.size() != tmp.size() - 1) {
        if (tmp[index] != -1) {
            count++;
            if (count == K) {
                result.push_back(tmp[index]);      // 요세푸스 숫자 저장
                tmp[index] = -1;                   // 해당 숫자 제거
                count = 0;                         // count 초기화
                index = (index + 1) % tmp.size();  // mod 연산으로 원형 배열처럼 사용, tmp.size()가 N + 1 이긴 하지만 mod N + 1 을 적용해야 정상적으로 나옴
                                                   // ex) N = 7일때, 7 mod 7을 하면 0이 되어버림
            } else {
                index = (index + 1) % tmp.size();  // mod 연산으로 원형 배열처럼 사용
            }
        } else {
            index = (index + 1) % tmp.size();  // mod 연산으로 원형 배열처럼 사용
        }
    }

    // 결과 출력
    for (int num : result) {
        if (result.size() == 1) {
            cout << '<' << num << '>';
            cout << '\n';
        } else if (num == result[0]) {
            cout << '<' << num << ", ";
        } else if (num == result[result.size() - 1]) {
            cout << num << '>';
            cout << '\n';
        } else {
            cout << num << ", ";
        }
    }
}

int main() {
    int N;
    int K;

    cin >> N >> K;

    // 초기화 과정
    vector<int> tmp(N + 1, -1);
    for (int i = 1; i < tmp.size(); i++) {
        tmp[i] = i;
    }

    vector<int> result;
    Josephus(K, tmp, result);
}