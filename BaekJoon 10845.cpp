#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	queue<int> queue;
	cin >> N;

	if (N < 1 || N > 10000)
	{
		return 0;
	}
	for (int i = 0; i < N; i++)
	{
		string S;
		int X;
		cin >> S;
		if (S == "push")
		{
			cin >> X;
			queue.push(X);
		}
		else if (S == "pop")
		{
			if (queue.size() == 0)
			{
				cout << "-1" << "\n";
			}
			else
			{
				cout << queue.front() << "\n";
				queue.pop();
			}
		}
		else if (S == "size")
		{
			cout << queue.size() << "\n";
		}
		else if (S == "empty")
		{
			if (queue.size() == 0)
			{
				cout << "1" << "\n";

			}
			else
			{
				cout << "0" << "\n";
			}
		}
		else if (S == "front")
		{ 
			if (queue.size() == 0)
			{
				cout << "-1" << "\n";
			}
			else
			{
				cout << queue.front() << "\n";
			}
		}
		else if (S == "back")
		{
			if (queue.size() == 0)
			{
				cout << "-1" << "\n";
			}
			else
			{
				cout << queue.back() << "\n";
			}
		}
	}
	return 0;
}