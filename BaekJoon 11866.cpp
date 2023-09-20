#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	queue<int> Q;

	for (int i = 1; i <= N; i++)
	{
		Q.push(i); //큐에 수 집어넣기
	}

	cout << "<";

	while (Q.size() > 1)
	{
		for (int i = 1; i < K; i++)
		{
			int first = Q.front();
			Q.pop();
			Q.push(first);
		}
		cout << Q.front() << ", ";
		Q.pop();
	}
	cout << Q.front() << ">\n";
}
