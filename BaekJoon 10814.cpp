#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility> //pair
using namespace std; 

bool compare(pair<int, string>a, pair<int, string>b)
{
	if (a.first == b.first)
	{
		return false;
	}
	else
	{
		return a.first < b.first;
	}
}

int main()
{
	int N;
	int Y;
	string S;
	cin >> N;
	vector<pair<int, string>> arr;
	for (int i = 0; i < N; i++)
	{
		cin >> Y >> S;
		arr.push_back(make_pair(Y, S));

	}

	stable_sort(arr.begin(), arr.end(), compare); //sort >> stable_sort, "값이 같으면 가입한 순서가 먼저 오도록,"

	for (int i = 0; i < N; i++)
	{
		cout << arr[i].first << " " << arr[i].second << "\n";
	}
}