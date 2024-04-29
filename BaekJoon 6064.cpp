#include <iostream> 
#include <vector>

using namespace std;

int gcd(int M, int N)
{
	if (N == 0)
	{
		return M;
	}
	return gcd(N, M % N);
}

int LCM(int M, int N)
{
	return (M * N) / gcd(M, N);
}

int main()
{
	int T, N, M, X, Y;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> M >> N >> X >> Y;
		int MAX = LCM(M, N);
		int result = -1;
		for (int j = X; j <= MAX; j += M)
		{
			int ny = j % N;
			if (ny == 0)
			{
				ny = N;
			}

			if (ny == Y)
			{
				result = j;
				break;
			}
		}
		cout << result << '\n';
	}
	return 0;
}