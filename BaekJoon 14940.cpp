#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

int N, M;
int arr[1001][1001];
int result[1001][1001];

int target_x, target_y;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { -1, 1, 0, 0 };

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({ x, y });

    result[x][y] = 1;
    while (!q.empty())
    {
        int frontx = q.front().first;
        int fronty = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = frontx + dx[i];
            int ny = fronty + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M)
            {
                if (result[nx][ny] == 0 && arr[nx][ny] != 0)
                {
                    result[nx][ny] = result[frontx][fronty] + 1;
                    q.push({ nx, ny });
                }
            }
        }
    }
}

void range()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] == 2)
            {
                target_x = i;
                target_y = j;
            }
        }
    }

    bfs(target_x, target_y);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] == 0)
            {
                cout << 0 << " ";
            }
            else
            {
                cout << result[i][j] - 1 << " ";
            }
        }
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }
    range();

    return 0;
}