#include <iostream>
#include <math.h>
using namespace std; 


int main()
{
	int N;
	int result = 0;
	cin >> N;
	for (int i = 5; i <= N; i *= 5)
	{
		result += (N / i);
	}
	cout << result;

	return 0;
}