#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int T;
	int N;
	cin >> T;
	vector <int> arr(12);
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	for (int i = 4; i < 12; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	}
	for (int i = 1; i <= T; i++)
	{
		cin >> N;
		cout << arr[N] << "\n";
	}
		
}