#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	int input;
	cin >> N;
	int result = 0;
	vector<int> arr;
	for (int i = 1; i <= N; i++)
	{
		cin >> input;
		if (input != 0)
		{
			arr.push_back(input);
		}
		else if (!arr.empty())
		{
			arr.pop_back();
		}
	}
	for (int element : arr)
	{
		result += element;
	}

	cout << result;
	return 0;
}



