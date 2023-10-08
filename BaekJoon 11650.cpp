#include <iostream>
#include <vector>
#include <algorithm> //sort
#include <utility> //pair를 사용하기 위함.
using namespace std;

int main()
{
	vector<pair<int, int>> arr;
	int N;
	int first;
	int second;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> first >> second;
		arr.push_back(make_pair(first,second));
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < N; i++)
	{
		cout << arr[i].first << " " << arr[i].second << "\n";
	}
}
