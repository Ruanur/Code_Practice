#include <iostream>
#include <queue>

using namespace std;

int N, M;
int arr[1001][1001];

// 익지 않은 토마토의 개수를 카운트하는 변수명 수정
int unripeTomatoes = 0;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void bfs()
{
	queue<pair<int, int>> q;

	// 모든 토마토의 위치를 큐에 저장
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 1) {
				q.push({ i, j });
			}
			else if (arr[i][j] == 0) { // 익지 않은 토마토의 개수를 카운트
				unripeTomatoes++;
			}
		}
	}

	// 큐가 빌 때까지 실행
	int days = 0;
	while (!q.empty())
	{
		int size = q.size(); // 해당 날짜에 익은 토마토의 개수를 기록하기 위해 큐의 크기를 저장

		for (int i = 0; i < size; i++)
		{
			int frontx = q.front().first;
			int fronty = q.front().second;

			q.pop();

			for (int j = 0; j < 4; j++)
			{
				int nx = frontx + dx[j];
				int ny = fronty + dy[j];

				if (nx >= 0 && nx < M && ny >= 0 && ny < N)
				{
					if (arr[nx][ny] == 0)
					{
						arr[nx][ny] = 1; // 익은 토마토로 변경
						unripeTomatoes--; // 익지 않은 토마토의 개수 감소
						q.push({ nx, ny });
					}
				}
			}
		}

		// 하루가 지남
		if (!q.empty()) // 큐가 비어있지 않다면 날짜 증가
			days++;
	}

	// 모든 토마토가 익었으면 최소 일수 출력, 그렇지 않으면 -1 출력
	if (unripeTomatoes == 0)
		cout << days;
	else
		cout << -1;
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}

	bfs();
}
