#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool def_check[1002];
bool bfs_check[1002];

vector<int> result_dfs;
vector<int> result_bfs;
vector<int> graph[10002];

void dfs(int x)
{
	def_check[x] = true;
	result_dfs.push_back(x);

	for (int i = 0; i < graph[x].size(); i++)
	{
		int y = graph[x][i];
		if (!def_check[y])
		{
			dfs(y);
		}
	}
}

void bfs(int start)
{
	queue<int> q;

	q.push(start);
	bfs_check[start] = true;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		result_bfs.push_back(x);

		for (int i = 0; i < graph[x].size(); i++)
		{
			int y = graph[x][i];
			if (!bfs_check[y])
			{
				q.push(y);
				bfs_check[y] = true;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M, V, a, b;
	cin >> N >> M >> V;
	for (int i = 1; i <= M; i++)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= N; i++)
	{
		sort(graph[i].begin(), graph[i].end()); //그래프는 1부터 시작하기 때문에 int i = 1이여야 한다. (처음에 int i = 0이라 해서 틀림)
	}
	dfs(V);
	for (int i = 0; i < result_dfs.size(); i++)
	{
		cout << result_dfs[i] << " ";
	}
	cout << "\n";
	bfs(V);
	for (int i = 0; i < result_bfs.size(); i++)
	{
		cout << result_bfs[i] << " ";
	}

	return 0;
}