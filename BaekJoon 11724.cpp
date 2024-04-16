#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[1001]; // 인접 리스트로 그래프 표현
bool visited[1001];    // 방문 여부를 저장하는 배열

void dfs(int node) {
    visited[node] = true;
    for (int i = 0; i < adj[node].size(); i++) {
        int nextNode = adj[node][i];
        if (!visited[nextNode]) {
            dfs(nextNode);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    // 그래프 생성
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a); // 양방향 그래프이므로 양쪽에 모두 추가
    }

    int connectedComponents = 0; // 연결 요소의 개수를 저장할 변수 초기화

    // 모든 노드에 대해 DFS 수행하여 연결 요소 개수 계산
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            dfs(i);
            connectedComponents++;
        }
    }

    cout << connectedComponents << "\n"; // 연결 요소 개수 출력

    return 0;
}
