#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	cout.tie(0);

	int N;
	cin >> N;
	int M;
	vector<int> arr;

	for (int i = 0; i < N; i++)
	{
		cin >> M;
		arr.push_back(M);
	}

	sort(arr.begin(), arr.end());

	for (auto N : arr)
	{
		cout << N << "\n";
	}
	return 0;
}