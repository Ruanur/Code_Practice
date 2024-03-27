#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 987654321; // 무한대를 나타내는 상수

// BFS 함수: 시작 정점부터 모든 정점까지의 최단 거리의 합을 계산
int bfs(vector<vector<int>>& graph, int start, int N) {
    vector<int> dist(N + 1, INF); // 각 정점까지의 최단 거리를 저장하는 배열, 초기값은 INF
    queue<int> q; // 방문할 정점을 저장하는 큐
    q.push(start); // 시작 정점을 큐에 추가
    dist[start] = 0; // 시작 정점까지의 거리는 0

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        // 현재 정점과 인접한 정점들을 탐색
        for (int next : graph[current]) {
            if (dist[next] == INF) { // 방문하지 않은 정점인 경우
                dist[next] = dist[current] + 1; // 최단 거리 업데이트
                q.push(next); // 다음 정점을 큐에 추가
            }
        }
    }

    int sum = 0; // 케빈 베이컨의 수의 합을 저장하는 변수
    // 모든 정점까지의 최단 거리의 합을 계산
    for (int i = 1; i <= N; ++i) {
        sum += dist[i];
    }
    return sum; // 케빈 베이컨의 수의 합 반환
}

int main() {
    int N, M;
    cin >> N >> M; // 정점의 개수 N, 간선의 개수 M 입력받기

    vector<vector<int>> graph(N + 1); // 그래프를 나타내는 인접 리스트

    // 간선 정보 입력받아 그래프 구성
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int min_kevin = INF; // 가장 작은 케빈 베이컨의 수를 저장하는 변수
    int min_user = -1; // 가장 작은 케빈 베이컨의 수를 가진 사용자를 저장하는 변수

    // 모든 정점에서 시작하여 케빈 베이컨의 수 계산
    for (int i = 1; i <= N; i++) {
        int kevin = bfs(graph, i, N); // 해당 정점에서의 케빈 베이컨의 수 계산
        if (kevin < min_kevin) { // 현재까지의 최소값보다 작은 경우 갱신
            min_kevin = kevin;
            min_user = i;
        }
    }

    // 결과 출력
    cout << min_user << '\n'; // 케빈 베이컨의 수가 가장 작은 사용자 출력

    return 0;
}
