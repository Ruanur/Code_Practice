#include <iostream>
#include <queue>

using namespace std; 

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	priority_queue<int> q;
	int N, M;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> M;
		if (M == 0)
		{
			if (q.empty())
			{
				cout << "0" << "\n";
			}
			else
			{
				cout << q.top() << "\n";
				q.pop();
			}
		}
		else
		{
			q.push(M);
		}
	}
	return 0;
}