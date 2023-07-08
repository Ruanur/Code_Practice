#include <iostream>
using namespace std;

int	sik(int n)
{
	return n * (n + 1) / 2;
}

int main(void)
{
	ios_base::sync_with_stdio(0);

	cin.tie(0);
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int n;
		cin >> n;

		int result = 0;

		for (int j = 1; j <= n; j++)
		{
			result += j * sik(j + 1);
		}
		cout << result << "\n";
	}
	return 0;
}