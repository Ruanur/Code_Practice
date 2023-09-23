#include <iostream>
#include <vector>
#include <algorithm> // sort 함수를 사용하기 위해 포함
#include <map>
#include <cmath>
using namespace std;

double avg(const vector<int>& arr)
{
	double sum = 0;
	double result = 0;
	double size = arr.size();
	for (int element : arr)
	{
		sum += element;
	}
	result = sum / size;
	return result;
}

int middle(vector<int>& arr)
{
	int result;
	for (int i = 0; i < arr.size() / 2; i++)
	{
		arr.erase(arr.begin());
	}
	result = arr.front();
	return result;

}

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

	vector<int> arr;
	int N;
	cin >> N;
	if (N % 2 == 0)
	{
		cout << "홀수만 입력하시오.";
		return 0;
	}
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		arr.push_back(input);
	}

	sort(arr.begin(), arr.end());

	int front = arr.front();
	int back = arr.back();

	double average = avg(arr);
	int fre = frequency(arr);
	int mid = middle(arr);

	cout << floor(average + 0.5) << "\n";
	cout << mid << "\n";
	cout << fre << "\n";
	cout << back - front << "\n";

	return 0;
}
