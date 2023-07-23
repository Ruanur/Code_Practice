#include <iostream>
using namespace std;
int main()
{
	string N;
	while (true)
	{
		cin >> N;
		if (N == "0")
		{
			return 0;
		}
		int result = 0;

		for (int i = 0; i < N.length(); i++)
		{
			if (N[i] == '1')
			{
				result += 2;
			}
			else if (N[i] == '0')
			{
				result += 4;
			}
			else
			{
				result += 3;
			}
			result++;
		}
		cout << result + 1 << endl;
	}
	return 0;
}

