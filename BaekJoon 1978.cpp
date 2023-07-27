#include <iostream>
using namespace std;

int main()
{
	int n, result = 0;
	int p, stack = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p;
		for (int a = 1; a <= p; a++)
		{
			if (p % a == 0)
			{
				stack++;
			}
		}
		if (stack == 2)
		{
			result++;
		}
		stack = 0;
	}
	cout << result << endl;
}
