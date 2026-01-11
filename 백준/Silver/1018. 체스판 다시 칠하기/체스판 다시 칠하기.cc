// 다시 풀기
#include <iostream>
#include <vector>

using namespace std;

int paintChessBoard(vector<vector<char>>& chess, int N, int M) {
    int result = 64;  // 8x8에서 최대 틀린 개수는 64이므로 10000 대신 64로 시작 가능

    // 모든 가능한 8x8 시작점 (i, j) 순회
    for (int i = 0; i <= N - 8; i++) {
        for (int j = 0; j <= M - 8; j++) {
            int countB = 0;  // 맨 왼쪽 위가 'B'여야 하는 판과 비교
            int countW = 0;  // 맨 왼쪽 위가 'W'여야 하는 판과 비교

            for (int l = i; l < i + 8; l++) {
                for (int k = j; k < j + 8; k++) {
                    // 체스판의 특징: (행 index + 열 index)가 짝수면 시작색과 같고, 홀수면 다름
                    if ((l + k) % 2 == 0) {
                        if (chess[l][k] != 'B') countB++;
                        if (chess[l][k] != 'W') countW++;
                    } else {
                        if (chess[l][k] != 'W') countB++;
                        if (chess[l][k] != 'B') countW++;
                    }
                }
            }
            // 이 8x8 영역에서의 최솟값 찾기
            int tempMin = min(countB, countW);
            // 전체 영역에서의 최솟값 갱신
            result = min(result, tempMin);
        }
    }
    return result;
}

int main() {
    int N, M;  // N이 행, M이 열
    cin >> N >> M;

    vector<vector<char>> chess(N, vector<char>(M));  // 체스판 선언
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c;
            cin >> c;
            chess[i][j] = c;
        }
    }

    int result = paintChessBoard(chess, N, M);

    cout << result << endl;
}