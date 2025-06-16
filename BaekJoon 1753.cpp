#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9; // 매우 큰 값 (무한대 대용)
vector<vector<pair<int, int>>> graph;
vector<int> dist;

void dijkstra(int start) {
    // min-heap: (거리, 정점)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int curDist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (curDist > dist[u]) continue;

        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].first;
            int weight = graph[u][i].second;

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({ dist[v], v });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E, K;
    cin >> V >> E >> K;

    graph.resize(V + 1);
    dist.resize(V + 1, INF);

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({ v, w });
    }

    dijkstra(K);

    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << "\n";
    }

    return 0;
}
