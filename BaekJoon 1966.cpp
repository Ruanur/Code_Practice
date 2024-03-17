#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int N, a, b, r;
	int count = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		count = 0;
		cin >> a >> b;
		queue<pair<int, int>> q;
		priority_queue<int> rank; //우선순위 큐
		for (int j = 0; j < a; j++)
		{
			cin >> r;
			q.push({ j, r });
			rank.push(r);
		}
		while (!q.empty())
		{
			int first = q.front().first;
			int value = q.front().second;
			q.pop();
			if (rank.top() == value)
			{
				rank.pop();
				++count;
				if (first == b)
				{
					cout << count << "\n";
					break;
				}
			}
			else
			{
				q.push({ first, value });
			}
		}
	}
}