#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// BFS 로직
int virus(int num, vector<vector<int>> &graph, vector<bool> &visited) {
    int result{0};

    queue<int> q;
    q.push(num);
    visited[num] = true;

    while (!q.empty()) {
        int tmp = q.front();
        q.pop();
        result++;

        for (int i = 0; i < graph[tmp].size(); i++) {
            if (!visited[graph[tmp][i]]) {
                q.push(graph[tmp][i]);
                visited[graph[tmp][i]] = true;
            }
        }
    }

    return (result - 1);
}

int main() {
    int numPC;
    cin >> numPC;

    vector<vector<int>> graph(numPC + 1);
    vector<bool> visited(numPC + 1, false);

    int pair;
    cin >> pair;

    // graph 생성 과정
    for (int i = 1; i <= pair; i++) {
        int pc1, pc2;
        cin >> pc1 >> pc2;

        graph[pc1].push_back(pc2);
        graph[pc2].push_back(pc1);
    }

    cout << virus(1, graph, visited) << '\n';
}