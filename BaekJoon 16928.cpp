#include <iostream>
#include <queue>
#include <vector>
#include <climits> // INT_MAX 사용을 위해 추가

using namespace std;

vector<pair<int, int>> ladder;
vector<pair<int, int>> snake;
vector<int> moves(101, INT_MAX); // 칸 별 이동 횟수를 저장하는 배열
vector<bool> visited(101, false); // 방문 여부를 저장하는 배열

// BFS 알고리즘을 사용하여 최소 이동 횟수를 계산하는 함수
int bfs() 
{
    queue<int> q;
    q.push(1); // 시작 칸은 1번 칸
    visited[1] = true;
    moves[1] = 0; // 시작 칸의 이동 횟수는 0

    while (!q.empty()) 
    {
        int current = q.front();
        q.pop();

        // 현재 칸에서 주사위를 던진 결과로 이동할 수 있는 칸을 확인
        for (int i = 1; i <= 6; i++) 
        {
            int next = current + i; // 다음 이동할 칸
            if (next > 100) continue; // 100을 초과하는 칸은 무시

            // 사다리를 타거나 뱀을 타는 경우 해당 칸으로 이동
            for (const auto& ladder_pos : ladder) 
            {
                if (ladder_pos.first == next)
                {
                    next = ladder_pos.second;
                }
            }
            for (const auto& snake_pos : snake) 
            {
                if (snake_pos.first == next)
                {
                    next = snake_pos.second;
                }
                
            }

            // 다음 칸을 방문하지 않았다면 이동 횟수를 업데이트하고 큐에 추가
            if (!visited[next]) 
            {
                visited[next] = true;
                moves[next] = moves[current] + 1;
                q.push(next);
            }
        }
    }

    return moves[100]; // 100번 칸의 이동 횟수 반환
}

int main() 
{
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) 
    {
        int x, y;
        cin >> x >> y;
        ladder.push_back(make_pair(x, y));
    }
    for (int i = 0; i < M; i++) 
    {
        int u, v;
        cin >> u >> v;
        snake.push_back(make_pair(u, v));
    }

    int result = bfs(); // 최소 이동 횟수 계산
    cout << result << endl;

    return 0;
}
