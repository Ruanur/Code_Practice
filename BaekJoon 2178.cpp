#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int arr[101][101];
int dist[101][101];


void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x,y });
	arr[x][y] = 0;
	dist[x][y]++;

	while (!q.empty())
	{
		int frontx = q.front().first;
		int fronty = q.front().second;

		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = frontx + dx[i];
			int ny = fronty + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M && arr[nx][ny] == 1)
			{
				dist[nx][ny] = dist[frontx][fronty] + 1;
				q.push({ nx,ny });
				arr[nx][ny] = 0;
			}
		}
	}
}


int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string row;
		cin >> row;
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = row[j] - '0';
		}
	}

	bfs(0,0);

	cout << dist[N - 1][M - 1];

	return 0;
}