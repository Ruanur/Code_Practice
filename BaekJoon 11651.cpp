#include <iostream>
#include <vector>
#include <algorithm> //sort
#include <utility> //pair를 사용하기 위함.
using namespace std;

bool compare(pair<int, int>a, pair<int, int>b) //사용자 정의 비교 함수
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}
	else
	{
		return a.second < b.second;
	}
}

int main()
{
	vector<pair<int, int>> arr;
	int N;
	int first;
	int second;
	int temp;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> first >> second;
		arr.push_back(make_pair(first, second));
	}

	sort(arr.begin(), arr.end(), compare); //compare: 사용자 정의 비교 함수

	for (int i = 0; i < N; i++)  
	{
		cout << arr[i].first << " " << arr[i].second << "\n";
	}
}
