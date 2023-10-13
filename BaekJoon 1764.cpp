#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	int M;
	string str;
	map<string, int> map;
	vector<string> arr;
	cin >> N >> M;
	for (int i = 0; i < N + M; i++)
	{
		cin >> str;
		map[str]++;
	}
	for (auto entry : map)
	{
		if (entry.second > 1)
		{
			arr.push_back(entry.first);
		}
	}
	cout << arr.size() << "\n";
	for (string element : arr)
	{
		cout << element << "\n";
	}

}