#include <iostream>
#include <vector>
using namespace std;

const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y, char color)
{
    visited[x][y] = true; // 방문 위치를 방문했다고 저장

    for (int i = 0; i < 4; ++i) 
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && !visited[nx][ny] && grid[nx][ny] == color) 
        {
            dfs(grid, visited, nx, ny, color);
        }
    }
}

int countRegions(vector<vector<char>>& grid) 
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int regions = 0;

    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < m; ++j) 
        {
            if (!visited[i][j]) 
            {
                dfs(grid, visited, i, j, grid[i][j]);
                regions++;
            }
        }
    }

    return regions;
}

// 색약 배열 변환 G -> R
int countRegionsWithGAsR(vector<vector<char>> grid) 
{
    int n = grid.size();
    int m = grid[0].size();

    // 배열(그림) 내에서 G를 R로 변환
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < m; ++j) 
        {
            if (grid[i][j] == 'G') 
            {
                grid[i][j] = 'R';
            }
        }
    }

    // 구역 수를 계산
    return countRegions(grid);
}

int main() {
    int N;
    cin >> N;

    vector<vector<char>> grid(N, vector<char>(N));
    for (int i = 0; i < N; ++i) 
    {
        for (int j = 0; j < N; ++j) 
        {
            cin >> grid[i][j];
        }
    }

    cout << countRegions(grid) << " " << countRegionsWithGAsR(grid) << endl;

    return 0;
}
