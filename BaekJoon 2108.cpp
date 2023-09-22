#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <cstdlib>
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

	int mostNumber = -1;
	int maxFre = 0;

	for (const auto& pair : freMap)
	{
		if (pair.second > maxFre)
		{
			mostNumber = pair.first;
			maxFre = pair.second;
		}
	}
	return mostNumber;
	//보류
}

int main()
{
	int N;
	vector<int> arr;
	cin >> N;
	if (N % 2 == 0)
	{
		cout << "홀수만 입력" << "\n";
		return 0;
	}
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		arr.push_back(input);
	}
	sort(arr.begin(), arr.end());
	cout << "정렬된 배열: ";
	for (int element : arr) {
		cout << element << " ";
	}
	int front = arr.front();
	int back = arr.back();
	cout << endl;

	double average = avg(arr);
	int mid = middle(arr);
	int fre = frequency(arr);

	cout << "=========================" << "\n";
	cout << floor(average) << "\n";
	cout << mid <<"\n";
	cout << fre <<"\n";
	cout << back - front << "\n";
}
