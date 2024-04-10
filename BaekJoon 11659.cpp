#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	int num;
	cin >> N >> M;
	int* arr = new int[N + 1];
	arr[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> num;
		arr[i] = arr[i - 1] + num;
	}
	int start, end;
	for (int i = 0; i < M; i++)
	{
		int result = 0;
		cin >> start >> end;
		result = arr[end] - arr[start - 1];
		cout << result << "\n";
	}
}
