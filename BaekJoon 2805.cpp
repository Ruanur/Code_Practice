#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M; //N: 나무의 수, M: 가져가려는 나무의 길이
	int* arr = new int[1000001];
	long long high = 0, low = 0, result = 0;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		if (high < arr[i])
		{
			high = arr[i];
		}
	}

	while (low <= high)
	{
		long long sum = 0;
		long long mid = (low + high) / 2;

		for (int i = 0; i < N; i++)
		{
			int temp = arr[i] - mid;
			if (temp > 0)
			{
				sum += temp;
			}
		}
		if (sum >= M)
		{
			result = mid;
			low = mid + 1;
		}
		else if (sum < M)
		{
			high = mid - 1;
		}
	}
	cout << result;
	return 0;
}