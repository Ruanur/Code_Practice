#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& field, int x, int y, int m, int n) {
    if (x < 0 || x >= m || y < 0 || y >= n || field[x][y] == 0) {
        return;
    }

    field[x][y] = 0; // 이미 방문한 배추는 0으로 표시

    // 상하좌우로 이동하며 배추가 있는지 확인
    dfs(field, x + 1, y, m, n);
    dfs(field, x - 1, y, m, n);
    dfs(field, x, y + 1, m, n);
    dfs(field, x, y - 1, m, n);
}

int countCabbageWorms(vector<vector<int>>& field) {
    int m = field.size(); // 행의 수
    int n = field[0].size(); // 열의 수

    int worms = 0; // 배추흰지렁이 수

    // 전체 배추 밭을 탐색하며 배추 영역을 찾음
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (field[i][j] == 1) { // 아직 방문하지 않은 배추를 발견하면
                dfs(field, i, j, m, n); // 해당 배추 영역을 모두 탐색
                worms++; // 배추흰지렁이 수 증가
            }
        }
    }

    return worms;
}

int main() {
    int T; // 테스트 케이스의 개수
    cin >> T;

    while (T--) {
        int M, N, K; // 가로길이, 세로길이, 배추 개수
        cin >> M >> N >> K;

        // 배추 밭 초기화, 배추 밭을 모두 0으로 초기화
        vector<vector<int>> field(M, vector<int>(N, 0));

        // 배추 위치 입력 및 표시
        for (int i = 0; i < K; ++i) {
            int X, Y;
            cin >> X >> Y;
            field[X][Y] = 1;
        }

        int worms = countCabbageWorms(field);
        cout << worms << "\n";
    }

    return 0;
}
