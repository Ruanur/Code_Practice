#include <iostream>
#include <queue>

using namespace std;

int arr[101][101][101]; // 3차원 배열로 변경하여 상자의 개수를 포함시킴

int M, N, H;

int dx[6] = { 0, 1, 0, -1, 0, 0 }; // 상자의 위, 아래로 이동하는 방향 추가
int dy[6] = { 1, 0, -1, 0, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 }; // 쌓아올려진 상자의 이동은 z축 방향으로 추가

int day = 0;

void bfs() {
    queue<pair<pair<int, int>, int>> q; // 상자의 좌표와 높이를 저장하는 큐
    // 익은 토마토의 위치를 큐에 넣음
    for (int k = 0; k < H; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (arr[i][j][k] == 1) {
                    q.push({ {i, j}, k });
                }
            }
        }
    }

    while (!q.empty()) {
        int size = q.size(); // 현재 큐에 있는 익은 토마토들의 개수만큼 반복
        for (int i = 0; i < size; i++) {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int z = q.front().second;
            q.pop();

            for (int j = 0; j < 6; j++) { // 상하좌우, 위아래로 이동
                int nx = x + dx[j];
                int ny = y + dy[j];
                int nz = z + dz[j];
                if (nx >= 0 && nx < N && ny >= 0 && ny < M && nz >= 0 && nz < H && arr[nx][ny][nz] == 0) {
                    q.push({ {nx, ny}, nz });
                    arr[nx][ny][nz] = 1;
                }
            }
        }
        day++; // 하루가 지남
    }
}

int main() {
    cin >> M >> N >> H;
    for (int k = 0; k < H; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> arr[i][j][k];
            }
        }
    }

    bfs();

    // 모든 토마토가 익었는지 확인
    for (int k = 0; k < H; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (arr[i][j][k] == 0) {
                    cout << "-1"; // 익지 않은 토마토가 있으면 -1 출력
                    return 0;
                }
            }
        }
    }

    cout << day - 1; // 모든 토마토가 익었으면 day - 1 출력

    return 0;
}
