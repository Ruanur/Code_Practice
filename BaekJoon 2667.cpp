#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

char arr[26][26]; // 2차원 배열로 변경
int N;

int startx = 0;
int starty = 0;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

vector<int> house_count;

void bfs(int x, int y, int& complex) // int& complex로 수정
{
	queue<pair<int, int>> q;
	q.push({ x, y });
	arr[x][y] = '0'; // 문자열 '0'으로 변경
	int count = 0;

	while (!q.empty())
	{
		int frontx = q.front().first;
		int fronty = q.front().second;

		q.pop();
		count++;

		for (int i = 0; i < 4; i++)
		{
			int nx = frontx + dx[i];
			int ny = fronty + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N && arr[nx][ny] == '1') // '1'로 변경
			{
				q.push({ nx, ny });
				arr[nx][ny] = '0'; // 문자열 '0'으로 변경
			}
		}
	}
	house_count.push_back(count);
	complex++;
}

void scan()
{
	int complex = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] == '1')
			{
				startx = i;
				starty = j;
				bfs(startx, starty, complex);
			}
		}
	}
	cout << complex << "\n";
	sort(house_count.begin(), house_count.end());
	for (int count : house_count)
	{
		cout << count << "\n";
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i]; // 한 줄씩 입력 받음
	}
	scan();
	return 0;
}
