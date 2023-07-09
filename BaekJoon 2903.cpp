#include <iostream>
using namespace std;

int main()
{
	int N, result;
	cin >> N;

	int x = 2;

	for (int i = 1; i <= N; i++)
	{
		x += (x - 1);
	}
	
	result = x * x;
	
	cout << result << endl;
}