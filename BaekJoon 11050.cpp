#include <iostream>
using namespace std;

int K_fac(int K);
int N_fac(int N);
int M_fac(int N);

int main()
{
	int N, K, result;
	cin >> N >> K;
	int M = N - K;

	N = N_fac(N);
	K = K_fac(K);
	M = M_fac(M);
	cout << N/(K*M);
}

int N_fac(int N)
{
	int N_result = 1;
	for (int i = 1; i <= N; i++)
	{
		N_result *= i;
	}
	return N_result;
}

int K_fac(int K)
{
	int K_result = 1;
	for (int i = 1; i <= K; i++)
	{
		K_result *= i;
	}
	return K_result;
}

int M_fac(int M)
{
	int M_result = 1;
	for (int i = 1; i <= M; i++)
	{
		M_result *= i;
	}
	return M_result;
}

