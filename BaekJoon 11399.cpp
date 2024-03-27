#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
	int N, M;
	cin >> N;
	vector<int> list;
	int sum = 0;
	int temp = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> M;
		list.push_back(M);
	}

	sort(list.begin(), list.end());

	for (int i : list)
	{
		temp += i;
		sum += temp;
	}
	cout << sum;
}

/*
bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.second < b.second;
}

int main()
{
	int N, A, B;
	vector<pair<int, int>> list;
	int sum = 0;
	int temp = 0;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> A >> B;
		list.push_back(make_pair(A, B));
	}

	sort(list.begin(), list.end(), compare);

	for (int i = 0; i < list.size(); i++)
	{
		temp += list[i].second;
		sum += temp;
		cout << sum;
	}
	
}
응용
*/