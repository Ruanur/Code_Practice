//파도반 수열 
#include <iostream>

using namespace std; 

long arr[101] = { 0 }; //99를 입력하면 int의 범위를 넘어섬

int main()
{
	int N, M;
	arr[1] = arr[2] = arr[3] = 1;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> M;
		for (int j = 4; j <= M; j++)
		{
			arr[j] = arr[j - 3] + arr[j - 2];
		}
		cout << arr[M] << "\n";
	}
}