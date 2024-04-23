#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
vector<int> arr[101];
int visit[101];

void dfs(int start)
{
	for (int i = 0; i < arr[start].size(); i++)
	{
		if (!visit[arr[start][i]])
		{
			visit[arr[start][i]] = 1;
			dfs(arr[start][i]); // 다음 정점으로 이동
		}
	}
}

int main()
{
	int a;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> a;
			if (a)
			{
				arr[i].push_back(j);
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		memset(visit, 0, sizeof(visit));
		dfs(i);
		for (int j = 0; j < N; j++)
		{
			cout << visit[j] << " ";
		}
		cout << "\n";
	}
}
