#include <iostream>
using namespace std;

int climb(int a, int b, int c)
{
	int N = 0;
	int temp = 0;
	int count = 0;
	while (N >= c)
	{
		N = N + a;
		count++;
		if (N < c)
		{
			N = N - b;
		}
	}
	return count;
}

int main()
{
	int A, B, V;
	cin >> A >> B >> V;
	cout << climb(A, B, V);
}