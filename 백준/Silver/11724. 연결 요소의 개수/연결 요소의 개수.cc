#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void bfs(const vector<vector<int>> &graph, vector<bool> &visited, int &count, const int numVertex) {
    for (int i = 1; i <= numVertex; i++) {
        if (!visited[i]) {
            queue<int> q;

            q.push(i);
            visited[i] = true;
            while (!q.empty()) {
                int cur = q.front();
                q.pop();

                for (int i = 0; i < graph[cur].size(); i++) {
                    if (!visited[graph[cur][i]]) {
                        q.push(graph[cur][i]);
                        visited[graph[cur][i]] = true;
                    }
                }
            }
            count++;
        }
    }
    cout << count << '\n';
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N + 1);
    vector<bool> visited(N + 1, false);

    // 그래프 생성
    while (M--) {
        int u, v;
        cin >> u >> v;

        // 무방향 그래프
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int count{0};

    bfs(graph, visited, count, N);
}