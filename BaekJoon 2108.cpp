#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <numeric>
using namespace std;

int frequency(vector<int>& arr)
{
	map <int, int> freMap;
	for (int element : arr)
	{
		freMap[element]++;
	}

	int maxFre = 0;
	vector<int> Frearr;

	for (const auto& pair : freMap)
	{
		if (pair.second > maxFre)
		{
			maxFre = pair.second;
			Frearr.clear();
			Frearr.push_back(pair.first);
		}
		else if (pair.second == maxFre)
		{
			Frearr.push_back(pair.first);
		}
	}
	if (Frearr.size() >= 2)
	{
		sort(Frearr.begin(), Frearr.end());
		Frearr.erase(Frearr.begin());
	}
	return Frearr.front();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	if (N % 2 == 0)
	{
		cout << "홀수만 입력하시오.";
		return 0;
	}

	vector<int> arr(N);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	double average = double(accumulate(arr.begin(), arr.end(), 0)) / double(N); // 평균 계산
	int mid = arr[N / 2]; // 중앙값 계산

	int fre = frequency(arr);
	int diff = arr.back() - arr.front(); // 최대값과 최소값의 차이 계산

	cout << floor(average + 0.5) << "\n"; // 반올림하여 출력
	cout << mid << "\n";
	cout << fre << "\n";
	cout << diff << "\n";

	return 0;
}
