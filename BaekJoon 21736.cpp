#include <iostream>
#include <queue>

using namespace std;

char arr[601][601];
int f_result = 0;

int N, M;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };


void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x, y });

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
				if (arr[nx][ny] == 'P')
				{
					f_result++;
					q.push({ nx, ny });
					arr[nx][ny] = '.'; //종료 조건이 없어서 메모리가 초과되었음
				}
				else if (arr[nx][ny] == 'O')
				{
					q.push({ nx, ny });
					arr[nx][ny] = '.'; //종료 조건이 없어서 메모리가 초과되었음.
				}
			}
		}
	}
}

void scan()
{
	int startx = 0;
	int starty = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 'I')
			{
				startx = i;
				starty = j;
			}
		}
	}
	bfs(startx, starty);

	if (f_result == 0)
	{
		cout << "TT";
	}
	else
	{
		cout << f_result;
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
	scan();
}