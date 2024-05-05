#include <iostream>
#include <queue>

using namespace std;

int N, K;
bool visited[100001];

void bfs(int a)
{
	queue<pair<int,int>> q;
	int count = 0;
	q.push(make_pair(a, 0));
	while (!q.empty())
	{
		int start = q.front().first;
		int count = q.front().second;
		q.pop();
		if (start == K)
		{
			cout << count;
			break;
		}
		if (start + 1 >= 0 && start + 1 < 100001)
		{
			if (!visited[start + 1])
			{
				visited[start + 1] = true;
				q.push(make_pair(start + 1, count + 1));
			}
		}
		if (start - 1 >= 0 && start - 1 < 100001)
		{
			if (!visited[start - 1])
			{
				visited[start - 1] = true;
				q.push(make_pair(start - 1, count + 1));
			}
		}
		if (start * 2 >= 0 && start * 2 < 100001)
		{
			if (!visited[start * 2])
			{
				visited[start * 2] = true;
				q.push(make_pair(start * 2, count + 1));
			}
		}
	}
}

int main()
{
	cin >> N >> K;

	bfs(N);
	
	return 0;
}